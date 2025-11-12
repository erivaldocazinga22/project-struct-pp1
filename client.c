#include "client.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
  int dia, mes, ano;
};

struct client {
  int num, telephone;
  char name[50];
  Data dataNasc;
};

struct no {
  Client valor;
  noClient *prox;
};

noClient *criarLista() { return NULL; };

noClient *criarNo(Client c) {
  noClient *l = (noClient *)malloc(sizeof(noClient));
  if (l) {
    l->valor = c;
    l->prox = NULL;
    return l;
  } else {
    printf("Erro de alocação...");
    return l;
  }
};

void listarClient(noClient *l) {
  while (l != NULL) {
    printf("%d \n %s \n %d/%d/%d", l->valor.num, l->valor.name,
           l->valor.dataNasc.dia, l->valor.dataNasc.mes, l->valor.dataNasc.ano);
    l = l->prox;
  }
};

noClient *addNo(noClient *l, Client c) {
  noClient *novo = criarNo(c);
  noClient *aux = l;
  if (aux == NULL)
    aux = novo;
  else {
    while (aux->prox != NULL) {
      aux = aux->prox;
    }

    novo = aux->prox;
    aux = novo;
  }

  return aux;
};

/* noClient *pesquisarNo(noClient *l, int num);
void removerNo(noClient *l, int num);
noClient *removeRepit(noClient *l);
void imprimirInOrderNasc(noClient *l); */
