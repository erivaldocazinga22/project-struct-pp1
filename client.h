typedef struct no noClient;
typedef struct client Client;
typedef struct data Data;

noClient *criarLista();
void listarClient(noClient *l);
noClient *criarNo(Client c);
noClient *addNo(noClient *l, Client c);
noClient *pesquisarNo(noClient *l, int num);
void removerNo(noClient *l, int num);
noClient *removeRepit(noClient *l);
void imprimirInOrderNasc(noClient *l);
