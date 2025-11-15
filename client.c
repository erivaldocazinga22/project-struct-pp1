#include "client.h"
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

void imprimir(noCliente *l)
{
  while (l != NULL)
  {
    printf("Numero: %d\nNome: %s\nTelefone: %d\nData Nasc: %02d/%02d/%04d\n\n",
           l->num, l->nome, l->telefone, l->dia, l->mes, l->ano);
    l = l->prox;
  }
}

noCliente *removerNo(noCliente *l, int num){
	noCliente *aux = l;
	noCliente *prev = NULL; /*auxiliar para pegar a ligaçao ao no anterior*/
	
	while(aux && aux->num!=num){
		prev = aux;
		aux = aux->prox;
	}
	
	if(!aux){
		printf("Número não encontrado!!\n");
		return l;
	}
	
	if(!prev){
		l = aux->prox;
		free(aux);
		return l;
	}
	
	
	prev->prox = aux->prox;
	free(aux);
	
	return l;
		
	
}

void pesquisarNo(noCliente *l, int num){
    noCliente *aux = l;
    
    while(aux){
    	
        if(aux->num == num){
        		printf("Numero: %d\nNome: %s\nTelefone: %d\nData Nasc: %02d/%02d/%04d\n\n",aux->num, aux->nome, aux->telefone, aux->dia, aux->mes, aux->ano);
        		break;
		}
        
            
        aux = aux->prox;
    }
    
     if(!aux) printf("Cliente de número %d não encontrado.\n", num);
    
}

noCliente* removerRepeticoes(noCliente* l) {
    noCliente* aux = l;

    while (aux) {
        noCliente* prev = aux;
        noCliente* tmp = aux->prox;

        while (tmp) {
            if (tmp->num == aux->num) {
                prev->prox = tmp->prox;
                free(tmp);
                tmp = prev->prox;
            } else {
                prev = tmp;
                tmp = tmp->prox;
            }
        }

        aux = aux->prox;
    }

    return l;
}

/*noCliente *imprimirInOrderNasc(noCliente *l);*/