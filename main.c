#include "client.h"
#include <stdio.h>
#include <stdlib.h>

#define DIM 50

/* TAD CLIENTE*/
void menu();
int data_eh_valida(int d, int m, int a); //serve para verificar se a data de nascimento eh valida
int ler_inteiro(char *s); //serve para garantir que o input deve ser um número e não um texto no scanf


int main() {
  system("chcp 65001 > null"); /*serve para aceitar acentuações para pcs que não
                            aceitam o locale.h*/

  menu();

  return 0;
}

int data_eh_valida(int dia, int mes, int ano) {
    // Verificar ano
    if (ano < 1 || ano > 2025) return 0;

    // Verificar mês
    if (mes < 1 || mes > 12) return 0;

    int dias_no_mes;

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias_no_mes = 31;
            break;

        case 4: case 6: case 9: case 11:
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

}

int ler_inteiro(char *str) {
  char *final;
  long valor = strtol(str, &final, 10);

  if (*final != '\0') {
    //printf("Erro: entrada não é um número válido.\n");
    return -1;
  }

  return (int)valor;
}


void menu() {

  noCliente *lista = criarLista();
  int opcao;
  int numero, telefone, dia, mes, ano;
  char nome[DIM], input[DIM], input_numero[DIM];

  do {
    printf("\n\n\t-------------------------------------\n\n");
    printf("\t\tTAD *LISTA DE CLIENTES* \n\n");
    printf("\t-------------------------------------\n\n");

    printf("\t\t1 - Adicionar Cliente\n");
    printf("\t\t2 - Remover Cliente\n");
    printf("\t\t3 - Pesquisar Cliente\n");
    printf("\t\t4 - Remover Repetidos\n");
    printf("\t\t5 - Imprimir\n");
    printf("\t\t6 - Imprimir por ordem de data_de_nascimento\n");
    printf("\t\t7 - SAIR\n");

    fflush(stdin);

    printf("\nEscolha uma Opcao\n");
    gets(input);
    opcao = ler_inteiro(input);

    switch (opcao) {
      case 1: {

        do {
          printf("Número: ");
          gets(input_numero);
          numero = ler_inteiro(input_numero);
          //Nao permite que o numero seja uma letra ou um negativo
          if (numero < 0) {
            printf("[ O Número deve ser inteiro positivo ]\n");
          }
        }while (numero < 0);

        fflush(stdin);
        printf("Nome: ");
        gets(nome);
        fflush(stdin);
        printf("telefone: ");
        scanf("%d", &telefone);
        do {
          printf("Data de nascimento(dd-mm-yyyy): ");
          scanf("%2d-%2d-%4d", &dia, &mes, &ano);

          if (!data_eh_valida(dia,mes,ano)) printf("\nFormato de data Inválido\n");
        }while (!data_eh_valida(dia,mes,ano));

        lista = addNo(lista, numero, nome, telefone, dia, mes, ano);
        system("cls");
        printf("CLiente Cadastrado com Sucesso!");
        break;
      }

      case 2: {
        printf("Número: ");
        scanf("%d", &numero);
        lista = removerNo(lista, numero);
        break;
      }
      case 3: {
        printf("Número: ");
        scanf("%d", &numero);
        system("cls");
        printf("---------------------------------------------------------\n\n");
        pesquisarNo(lista, numero);
        printf("---------------------------------------------------------\n\n");
        break;
      }
      case 4:
        lista = removeRepeticoes(lista);
        break;
      case 5: {
        system("cls");
        printf("---------------------------------------------------------\n\n");
        imprimir(lista);
        printf("---------------------------------------------------------\n\n");
        break;
      }

      case 6:
        // printf("Em desenvolvimento!!!");
        imprimirInOrderNasc(lista);
        break;

      case 7:
        return;
        break;

      default:
        printf("Opcao Invalida!\n");
      }
  } while (opcao != 7);
}
