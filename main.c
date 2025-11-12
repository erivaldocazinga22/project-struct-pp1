#include "client.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  noClient *lista = criarLista();
  Client c;
  c.num = 1;
  c.telephone = 987654356;
  strcpy(c.name, "iva");
  c.dataNasc.ano = 2025;
  c.dataNasc.mes = 12;
  c.dataNasc.dia = 1;
  printf("%d", c.dataNasc.ano);
  /*
  Client c1;
    c1.num = 2;
    c1.telephone = 987654356;
    strcpy(c1.name, "alguem");
    c1.dataNasc.ano = 2025;
    c1.dataNasc.mes = 6;
    c1.dataNasc.dia = 15;*/
  lista = addNo(lista, c);
  /* addNo(lista, c1); */

  listarClient(lista);
}