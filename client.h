#ifndef client_H
#define client_H

typedef struct no noCliente;

noCliente *criarLista();
noCliente *criarNo(int numero,char *nome, int telefone, int dia,int mes,int ano);
noCliente *addNo(noCliente *l, int numero,char *nome, int telefone, int dia,int mes,int ano);
noCliente *removerNo(noCliente *l,int num);
noCliente *removeRepeticoes(noCliente *l);
noCliente *imprimirInOrderNasc(noCliente *l);
void imprimir(noCliente *l);
void pesquisarNo(noCliente *l, int num);

#endif