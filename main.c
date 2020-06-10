#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itree.h"
#include "recorrer.h"
#include "operaciones.h"


//==============================================================================
/*
Recibe el nombre de una operacion y retorna un numero correspondiente a la
misma.
*/
int opcion (char* operacion) {
  if (!strcmp(operacion, "i")) return 1; /* 1: Insertar */
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
    printf ("Ingrese la una opcion y un intervalo\n");
    scanf ("%s", operacion);
    op = opcion (operacion);
    if ( op == 1 || op == 2 || op == 3 ) {
      printf("Operaciones con intervalos\n");
      scanf(" [%lf, %lf]", &a, &b);
      if (a < b) { // formato de intervalo invalido
        Intervalo* intervalo = crear_intervalo (a, b); // crea el intervalo [a, b]
        /* interprete */
        switch (op) {
          // Insertar
          case 1:
            printf("Insertar\n");
            itree_insertar ( &arbol, intervalo);
          break;
          // Elimnar
          case 2:
            printf("Eliminar\n");
            //itree_eliminar (intervalo, arbol);
            free(intervalo);
          break;
          // Intersectar
          case 3:
            printf("Intersecar\n");
            itree_intersecar (intervalo, arbol);
            free(intervalo);
          break;
          // Operacion invalida
          default:
            printf("Operacion no valida\n");
          break;
          } //switch  
      } //if a b
    }
    printf("paso del if a b %d\n", op);

    if ( op == 4 || op == 5 || op == 0 ) {
      printf("Operaciones sin intervalos\n");
      switch (op) {
         // DFS
        case 4:
          printf("dfs\n");
          itree_recorrer_dfs (arbol, mostrar_intervalo);
        break;
        // BFS
        case 5:
          printf("bfs\n");
          itree_recorrer_bfs (arbol, mostrar_intervalo);
        break;
        // Salir
        case 0:
          printf("Adios\n");
          itree_destruir (arbol);
        break;
        // Operacion invalida
          default:
            printf("Operacion no valida\n");
          break;
      }
    }
    printf("paso del if string\n");
  }
  return 0;
}