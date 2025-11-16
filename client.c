#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct no
{
  int num;
  int telefone;
  char nome[50];
  int dia, mes, ano;
  struct no *prox;
};

noCliente *criarLista() { return NULL; }

noCliente *criarNo(int numero, char *nome, int telefone, int dia, int mes,
                   int ano)
{
  noCliente *l = (noCliente *)malloc(sizeof(noCliente));
  if (!l)
  {
    printf("Erro de alocação...\n");
    return NULL;
  }

  l->num = numero;
  l->telefone = telefone;
  strcpy(l->nome, nome ? nome : "");
  l->dia = dia;
  l->mes = mes;
  l->ano = ano;
  l->prox = NULL;

  return l;
}

noCliente *addNo(noCliente *l, int numero, char *nome, int telefone, int dia,
                 int mes, int ano)
{
  noCliente *novo = criarNo(numero, nome, telefone, dia, mes, ano);
  if (!novo)
    return l; /* Alocacao falhou, retorna a lista original */

  if (l == NULL)
  {
    return novo; /* Primeiro item da lista */
  }

  noCliente *aux = l;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }

  aux->prox = novo;

  return l;
}

void imprimir(noCliente *l)
{

  // Cabeçalho da tabela
  printf("\n");
  printf("+--------+--------------------------------+------------+------------|\n");
  printf("| Numero | Nome                           | Telefone   | Data Nasc  |\n");
  printf("+--------+--------------------------------+------------+------------|\n");

  // Verifica se a lista está vazia
  if (l == NULL)
  {
    printf("|                  Nenhum cliente cadastrado                        |\n");
    printf("+--------+--------------------------------+------------+------------|\n");
    return;
  }

  // Imprime cada cliente5

  while (l != NULL)
  {
    printf("| %-6d | %-30s | %-10d | %02d/%02d/%04d |\n",
           l->num, l->nome, l->telefone, l->dia, l->mes, l->ano);
    l = l->prox;
  }

  // Rodapé da tabela
  printf("+--------+--------------------------------+------------+------------+\n");
  printf("\n");
}

/*
 **
 * RemoverNO
 * 1-Percorrer todos os elementos
 * 2- se encontrar um elemento com o mesmo numero faz o free()
 * 3- senao Apresente a mensagem de no nao encontrado
 */

noCliente *removerNo(noCliente *l, int num)
{
  noCliente *aux = l;
  noCliente *prev = NULL; /*auxiliar para pegar a ligaçao ao no anterior*/
  int encontrou = 0;      // Flag para saber se encontrou pelo menos um

  while (aux)
  {
    if (aux->num == num)
    {
      encontrou = 1;

      if (prev == NULL)
      {
        // Removendo o primeiro nó
        l = aux->prox; // Atualiza o início da lista
        free(aux);
        aux = l; // Continua do novo início
      }
      else
      {
        // Removendo nó no meio ou fim
        prev->prox = aux->prox;
        free(aux);
        aux = prev->prox; // Continua do próximo após prev
      }
    }
    else
    {
      // Avança normalmente
      prev = aux;
      aux = aux->prox;
    }
  }

  if (!encontrou)
  {
    printf("\tNúmero não encontrado!!\n");
  }

  return l;
}

void pesquisarNo(noCliente *l, int num)
{
  noCliente *aux = l;
  int cliente_encontrado = 0;

  // Cabeçalho da tabela
  printf("\n");
  printf("+--------+--------------------------------+------------+------------|\n");
  printf("| Numero | Nome                           | Telefone   | Data Nasc  |\n");
  printf("+--------+--------------------------------+------------+------------|\n");

  while (aux)
  {

    if (aux->num == num)
    {

      printf(
          "| %-6d | %-30s | %-10d | %02d/%02d/%04d |\n",
          aux->num, aux->nome, aux->telefone, aux->dia, aux->mes, aux->ano);
      cliente_encontrado = 1;
    }
    aux = aux->prox;
  }

  if (!aux && !cliente_encontrado)
    printf("\t  Cliente  não encontrado.\n");

  // Rodapé da tabela
  printf("+--------+--------------------------------+------------+------------+\n");
  printf("\n");
}

noCliente *removeRepeticoes(noCliente *l)
{
  noCliente *aux = l;

  while (aux)
  {
    noCliente *prev = aux;
    noCliente *tmp = aux->prox;

    while (tmp)
    {
      if (tmp->num == aux->num)
      {
        prev->prox = tmp->prox;
        free(tmp);
        tmp = prev->prox;
      }
      else
      {
        prev = tmp;
        tmp = tmp->prox;
      }
    }

    aux = aux->prox;
  }

  return l;
}

/**
 * Comparador para qsort
 * Ordena por data de nascimento (ano, mês, dia)
 */
int compararNascimento(const void *a, const void *b)
{
  noCliente *c1 = *(noCliente **)a;
  noCliente *c2 = *(noCliente **)b;

  if (c1->ano != c2->ano)
    return c1->ano - c2->ano;
  if (c1->mes != c2->mes)
    return c1->mes - c2->mes;
  return c1->dia - c2->dia;
}

/**
 * imprimirInOrderNasc
 * -------------------
 * Imprime a lista de clientes em ordem crescente de data de nascimento.
 * Complexidade: O(n log n) - qsort
 */
noCliente *imprimirInOrderNasc(noCliente *l)
{

  // Cabeçalho da tabela
  printf("\n");
  printf("+--------+--------------------------------+------------+------------|\n");
  printf("| Numero | Nome                           | Telefone   | Data Nasc  |\n");
  printf("+--------+--------------------------------+------------+------------|\n");

  if (l == NULL)
  {
    printf("|                  Nenhum cliente cadastrado                        |\n");
    printf("+--------+--------------------------------+------------+------------|\n");
    return l;
  }

  /* Conta os nós da lista */
  int n = 0;
  noCliente *aux = l;
  while (aux != NULL)
  {
    n++;
    aux = aux->prox;
  }

  noCliente *arr[n];
  aux = l;
  for (int i = 0; i < n; i++)
  {
    arr[i] = aux;
    aux = aux->prox;
  }

  qsort(arr, n, sizeof(noCliente *), compararNascimento);

  for (int i = 0; i < n; i++)
  {
    aux = arr[i];
    printf("| %-6d | %-30s | %-10d | %02d/%02d/%04d |\n",
           aux->num, aux->nome, aux->telefone, aux->dia, aux->mes, aux->ano);
  }

  // Rodapé da tabela
  printf("+--------+--------------------------------+------------+------------+\n");
  printf("\n");

  return l;
}

int contarClientes(noCliente *lista)
{
  int contador = 0;
  noCliente *aux = lista;

  while (aux != NULL)
  {
    contador++;
    aux = aux->prox;
  }

  return contador;
}
int calcularIdade(int dia, int mes, int ano)
{
  // Obter data atual do sistema
  time_t t = time(NULL);
  struct tm *dataAtual = localtime(&t);

  // Extrair ano, mês e dia atuais
  int anoAtual = dataAtual->tm_year + 1900; // tm_year conta desde 1900
  int mesAtual = dataAtual->tm_mon + 1;     // tm_mon vai de 0-11
  int diaAtual = dataAtual->tm_mday;

  // Calcular idade base
  int idade = anoAtual - ano;

  // Ajustar se ainda não fez aniversário este ano
  if (mesAtual < mes)
  {
    idade--;
  }
  else if (mesAtual == mes && diaAtual < dia)
  {
    idade--;
  }

  return idade;
}

float calcularIdadeMedia(noCliente *lista)
{
  // Se lista vazia, retorna 0
  if (lista == NULL)
  {
    return 0.0;
  }

  int somaIdades = 0;
  int totalClientes = 0;
  noCliente *aux = lista;

  // Percorrer lista somando idades
  while (aux != NULL)
  {
    int idade = calcularIdade(aux->dia, aux->mes, aux->ano);
    somaIdades += idade;
    totalClientes++;
    aux = aux->prox;
  }

  // Calcular média
  float media = (float)somaIdades / totalClientes;

  return media;
}
