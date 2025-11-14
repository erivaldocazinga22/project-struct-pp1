typedef struct no noCliente;

noCliente *criarLista();
void imprimir(noCliente *l);
noCliente *criarNo(int numero,char *nome, int telefone, int dia,int mes,int ano);
noCliente *addNo(noCliente *l, int numero,char *nome, int telefone, int dia,int mes,int ano);
noCliente *pesquisarNo(noCliente *l, int num);
void removerNo(noCliente *l, int num);
noCliente *removeRepeticoes(noCliente *l);
void imprimirInOrderNasc(noCliente *l);
