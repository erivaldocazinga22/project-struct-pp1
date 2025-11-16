#include <ctype.h>

#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 50

/* TAD CLIENTE*/
void menu();
int data_eh_valida(int d, int m, int a); // serve para verificar se a data de nascimento eh valida
int ler_inteiro(char *s);
int validar_nome(char *s); // serve para garantir que o input deve ser um número e não um texto no scanf

int main()
{
  system("chcp 65001 > null"); /*serve para aceitar acentuações para pcs que não
                            aceitam o locale.h*/

  menu();

  return 0;
}

int data_eh_valida(int dia, int mes, int ano)
{
  // Verificar ano
  if (ano < 1 || ano > 2025)
    return 0;

  // Verificar mês
  if (mes < 1 || mes > 12)
    return 0;

  int dias_no_mes;

  switch (mes)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    dias_no_mes = 31;
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    dias_no_mes = 30;
    break;

  case 2:
    // Verificar bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
      dias_no_mes = 29;
    else
      dias_no_mes = 28;
    break;

  default:
    return 0;
  }

  if (dia < 1 || dia > dias_no_mes)
  {
    return 0;
  }
}

int ler_inteiro(char *str)
{
  char *final;
  long valor = strtol(str, &final, 10);

  if (*final != '\0')
  {
    // printf("Erro: entrada não é um número válido.\n");
    return -1;
  }

  return (int)valor;
}

int validar_nome(char *nome)
{
  // Verifica se o nome está vazio
  if (nome == NULL || strlen(nome) == 0)
  {
    printf("[ O nome não pode estar vazio! ]\n");
    return 0;
  }

  // Verifica se contém apenas espaços em branco
  int apenasEspacos = 1;
  for (int i = 0; nome[i] != '\0'; i++)
  {
    if (nome[i] != ' ' && nome[i] != '\t' && nome[i] != '\n')
    {
      apenasEspacos = 0;
      break;
    }
  }

  if (apenasEspacos)
  {
    printf("[ O nome não pode conter apenas espaços! ]\n");
    return 0;
  }

  // Verifica se o tamanho é maior que 30
  if (strlen(nome) > 30)
  {
    printf("[ O nome não pode ter mais de 30 caracteres! ]\n");
    return 0;
  }

  return 1; // Nome válido
}

void menu()
{

  noCliente *lista = criarLista();
  int opcao, opcao_eliminar_no;
  int numero, telefone, dia, mes, ano;
  char nome[DIM], input[DIM], input_numero[DIM], input_nome[DIM], input_telefone[DIM], input_eliminar_no[DIM], input_pesquisar_no[DIM], input_remover_no[DIM];

  do
  {
    printf("\n\n\t+-----------------------------------+\n");
    printf("\t|\t TAD *LISTA DE CLIENTES*    |\n");
    printf("\t+-----------------------------------+\n\n");

    printf("\t\t1 - Adicionar\n\n");
    printf("\t\t2 - Remover \n\n");
    printf("\t\t3 - Pesquisar \n\n");
    printf("\t\t4 - Remover Repetidos\n\n");
    printf("\t\t5 - Listar\n\n");
    printf("\t\t6 - Listar por ordem de data_de_nascimento\n\n");
    printf("\t\t7 - Estatísticas\n\n");
    printf("\t\t8 - Informações sobre o trabalho\n\n");
    printf("\t\t9 - SAIR\n");
    fflush(stdin);

    printf("\n\tEscolha uma Opcao ->  ");
    gets(input);
    opcao = ler_inteiro(input);

    switch (opcao)
    {
    case 1:
    {

      // INPUT NUMERO
      do
      {
        printf("\n\t| Número:    ");
        gets(input_numero);
        numero = ler_inteiro(input_numero);
        // Nao permite que o numero seja uma letra ou um negativo
        if (numero < 0)
        {
          printf("[ O Número deve ser inteiro positivo ]\n");
        }
        else if (numero > 9999)
        {
          printf("[ O Número deve ter no máximo inteiro 4 dígitos ]\n");
        }
      } while (numero < 0 || numero > 9999);

      // INPUT NOME
      fflush(stdin);
      do
      {
        printf("\n\t| Nome:     ");
        gets(nome);
      } while (!validar_nome(nome));

      // INPUT TELEFONE
      fflush(stdin);
      do
      {
        printf("\n\t| Telefone: ");
        gets(input_telefone);
        telefone = ler_inteiro(input_telefone);
        // Nao permite que o telefone seja uma letra ou um negativo
        if (telefone < 0)
        {
          printf("\t[ O Telefone deve ser inteiro positivo ]\n");
        }
        else if (telefone > 9999999999)
        {
          printf("\t[ O Telefone deve ter no máximo 10 dígitos ]\n");
        }
      } while (telefone < 0 || telefone > 9999999999);

      // INPUT DATA DE NASCIMENTO
      fflush(stdin);
      do
      {
        printf("\n\t| Data de nascimento(dd-mm-yyyy):   ");
        scanf("%2d-%2d-%4d", &dia, &mes, &ano);
        if (!data_eh_valida(dia, mes, ano))
        {
          printf("\tFormato de data Inválido\n");
        }
      } while (!data_eh_valida(dia, mes, ano));

      fflush(stdin);

      lista = addNo(lista, numero, nome, telefone, dia, mes, ano);
      system("cls");
      printf("CLiente Cadastrado com Sucesso!");
      break;
    }

    case 2:
    {
      printf("\tNúmero:     ");
      gets(input_remover_no);
      numero = ler_inteiro(input_remover_no);

      fflush(stdin);
      do
      {
        printf("\n\tEsta acção irá remover todos os clientes com o número %d. Deseja continuar [1-Sim/0-Não] ->   ", numero);
        gets(input_eliminar_no);
        opcao_eliminar_no = ler_inteiro(input_eliminar_no);
        if (opcao_eliminar_no < 0 || opcao_eliminar_no > 1)
        {
          printf("Opção Inválida");
        }
      } while (opcao_eliminar_no < 0 || opcao_eliminar_no > 1);

      if (opcao_eliminar_no == 0)
      {
        printf("\tMissão Abortada");
      }
      else
      {
        lista = removerNo(lista, numero);
            }

      break;
    }
    case 3:
    {
      system("cls");

      printf("\tNúmero a pesquisar: ");
      gets(input_pesquisar_no);
      numero = ler_inteiro(input_pesquisar_no);

      system("cls");
      printf("---------------------------------------------------------\n\n");
      pesquisarNo(lista, numero);
      break;
    }
    case 4:
      lista = removeRepeticoes(lista);
      break;
    case 5:
    {
      system("cls");
      imprimir(lista);
      break;
    }

    case 6:
      system("cls");
      imprimirInOrderNasc(lista);
      break;

    case 7:
    {
      system("cls");
      printf("\n\t+---------------------------------+\n");
      printf("\t|\t Estatísticas             |\n");
      printf("\t+---------------------------------+\n");
      printf("\t\tTotal de clientes : %d \n", contarClientes(lista));
      printf("\t\tIdade Média:        %.2f\n", calcularIdadeMedia(lista));
      printf("\t+---------------------------------+\n");

      break;
    }

    case 8:
    {
      system("cls");
      printf("\n╔══════════════════════════════════════════════════════════════╗\n");
      printf("║   BEM-VINDO AO SISTEMA DE GESTÃO DE CLIENTES                 ║\n");
      printf("╚══════════════════════════════════════════════════════════════╝\n\n");

      printf("\tEste sistema foi desenvolvido para aplicar os nossos conhecimentos\n");
      printf("\tsobre Tipos Abstratos de Dados e Listas encadeadas simples, aprendidos com a \n");
      printf("\tEstimada Professora Sílvia António. \n\n");

      printf("┌──────────────────────────────────────────────────────────────┐\n");
      printf("│                     Dados do Grupo                           │\n");
      printf("├──────────────────────────────────────────────────────────────┤\n");
      printf("│  Grupo Nº 17                                                 │\n");
      printf("│  Integrantes:                                                │\n");
      printf("│    -> Diangienda Nkana  - 20240092                           │\n");
      printf("│    -> Ivanildo Almeida  - 20240147                           │\n");
      printf("│    -> Erivaldo Caginga  - 20241000                           │\n");
      printf("│  Turma: 2º Ano T1                                            │\n");
      printf("└──────────────────────────────────────────────────────────────┘\n\n");
      printf("Ao fazer este projeto, aprendemos conceitos fundamentais sobre Tipos Abstratos de Dados (TAD) e \n");
      printf("estruturas de dados dinâmicas, especificamente listas ligadas, aplicando-os num contexto prático de gestão de clientes.");
      break;
    }

    case 9:
    {
      return;
      break;
    }

    default:
      printf("Opcao Invalida!\n");
    }

  } while (opcao != 9);
}
