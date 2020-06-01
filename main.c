#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

//==============================================================================
/*
Recibe el nombre de una operacion y retorna un numero correspondiente a la
misma.
*/
int opcion (char* operacion) {
  if (!strcmp(operacion, "i")) return 1; /* 1: Imprimir */
  if (!strcmp(operacion, "e")) return 2; /* 2: Eliminar */
  if (!strcmp(operacion, "?")) return 3; /* 3: Intersectar */
  if (!strcmp(operacion, "dfs")) return 4; /* 4: dfs */
  if (!strcmp(operacion, "bfs")) return 5; /* 5: bfs */
  if (!strcmp(operacion, "salir")) return 0; /* 0: salir */
  return -1; /* operacion no valida */
}

//==============================================================================

int main() {

  char operacion[8];
  double a, b;
  int op = -1;

  AVL* arbol = itree_crear (); // inicializa el arbol

  /* Formato de entrada "opcion [a, b]" */
  while (op != 0) {
    if(scanf("%s [%lf, %lf]", operacion, &a, &b) != 3) return 0; // read error
    op = opcion (operacion);

    if (a > b) return 0; // formato de intervalo invalido

    Intervalo* intervalo = crear_intervalo (a, b); // crea el intervalo [a, b]

    /* interprete */
    switch (op) {
      // Insertar
      case 1:
        printf("Insertar\n");
        itree_insertar (intervalo, arbol);
      break;
      // Elimnar
      case 2:
        printf("Elimnar\n");
        itree_eliminar (intervalo, arbol);
        free(intervalo);
      break;
      // Intersectar
      case 3:
        printf("Intersectar\n");
        itree_intersectar (intervalo, arbol);
        free(intervalo);
      break;
      // DFS
      case 4:
        printf("dfs\n");
        itree_recorrer_dfs (arbol);
        free(intervalo);
      break;
      // BFS
      case 5:
        printf("bfs\n");
        itree_recorrer_bfs (arbol);
        free(intervalo);
      break;
      // Salir
      case 0:
        printf("Adios\n");
        itree_destruir (arbol);
        free(intervalo);
      // Operacion invalida
      default:
        printf("Operacion no valida\n");
      break;
    }
  }

  return 0;
}
