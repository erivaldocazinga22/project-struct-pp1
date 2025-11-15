#include <stdio.h>
#include <stdlib.h>
#include "client.h"

#define DIM 50

/* TAD CLIENTE*/
void menu();

int main(int argc, char *argv[]) {
	system("chcp 65001 > null"); /*serve para aceitar acentuações para pcs que não aceitam o locale.h*/
	
	menu();
  
	return 0;
}



void menu(){
	
	
	noCliente *lista = criarLista();
	int opcao;
	int numero,telefone,dia,mes,ano;
	char nome[DIM];
		
		
	do
	{
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
		
		printf("\nEscolha uma Opcao\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:{
				
				printf("Número: ");
				scanf("%d",&numero);
				printf("telefone: ");
				scanf("%d",&telefone);
				printf("Data de nascimento(dd-mm-yyyy): ");
				scanf("%2d-%2d-%4d",&dia,&mes,&ano);
				fflush(stdin);
				printf("Nome: ");
				gets(nome);
				
				lista = addNo(lista, numero,nome,telefone,dia,mes,ano);
				system("cls");
				break;
			}
			
			case 2:{
				printf("Número: ");
				scanf("%d",&numero);
				lista = removerNo(lista,numero);
				break;
			}
			case 3:{
				printf("Número: ");
				scanf("%d",&numero);
				system("cls");
      		    printf("---------------------------------------------------------\n\n");
				pesquisarNo(lista,numero);
      		    printf("---------------------------------------------------------\n\n");
				break;
			}
      		case 4:
               lista = removerRepeticoes(lista);
      			break;
      		case 5:{
      		system("cls");
      		printf("---------------------------------------------------------\n\n");
      		imprimir(lista);
      		printf("---------------------------------------------------------\n\n");
				break;
			  }
                
      		case 6:
                printf("Em desenvolvimento!!!");
      			break;
			
			case 7:
				return;
			break;
			
			default:
				printf("Opcao Invalida!\n");
		}
	}while (opcao != 7);

}                                           
	
