#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int main()
{

  noCliente *lista = criarLista();

  // ⭐ Adicionando 4 elementos do nada so para testar msm...
  lista = addNo(lista, 1, "Carlos Alberto", 923111222, 10, 5, 2002);
  lista = addNo(lista, 2, "Maria João", 923555444, 21, 3, 1999);
  lista = addNo(lista, 3, "Pedro Silva", 922777666, 30, 8, 2001);
  lista = addNo(lista, 4, "Ana Ferreira", 921999888, 15, 1, 2000);

  imprimir(lista);

  return 0;
}
