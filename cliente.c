/**
 * Seja Bem-vindo aos nossos bastidores, onde a magia acontece 🧙🪄
 */

#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
  int num;
  int telefone;
  char nome[50];
  int dia, mes, ano;
  struct no *prox;
};

noCliente *criarLista() { return NULL; }

noCliente *criarNo(int numero, char *nome, int telefone, int dia, int mes, int ano)
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

void imprimir(noCliente *l)
{
  while (l != NULL)
  {
    printf("Numero: %d\nNome: %s\nTelefone: %d\nData Nasc: %02d/%02d/%04d\n\n",
           l->num, l->nome, l->telefone, l->dia, l->mes, l->ano);
    l = l->prox;
  }
}

noCliente *addNo(noCliente *l, int numero, char *nome, int telefone, int dia,int mes, int ano)
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

/* noClient *pesquisarNo(noClient *l, int num);
void removerNo(noClient *l, int num);
noClient *removeRepit(noClient *l);
void imprimirInOrderNasc(noClient *l); */
