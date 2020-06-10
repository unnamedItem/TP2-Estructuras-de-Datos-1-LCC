#include <stdio.h>
#include <stdlib.h>
#include "recorrer.h"

/*inorder*/
void itree_recorrer_dfs (AVL *arbol, FuncionVisitante visit) {
  if (arbol == NULL) return;

  itree_recorrer_dfs (arbol->izq, visit);

  visit (arbol->dato);

  itree_recorrer_dfs (arbol->der, visit);
}

int itree_altura( AVL* arbol ) {

  if ( arbol == NULL){ 
    return 0;
  }

  else {
    int rAltura = itree_altura( arbol->der );
    int lAltura = itree_altura( arbol->izq );
   
    if ( rAltura > lAltura) {
      return rAltura + 1;
      }

    else {
      return lAltura + 1;  
    }
  }
}

void imprimir_nivel( AVL* arbol, int nivel, FuncionVisitante visit) {
  //nivel es asignado en recorrer bfs
  if ( arbol == NULL) // si no hay nodo no hace nada
        return; 
  else if ( nivel == 1) {
    visit( arbol->dato); // si nivel == 1 imprime el nivel
  }
  else if ( nivel > 1) {
    imprimir_nivel( arbol->izq, nivel-1, visit );
    imprimir_nivel( arbol->der, nivel-1, visit );
  }
}

void itree_recorrer_bfs( AVL *arbol, FuncionVisitante visit ) {

  int altura = itree_altura( arbol);
  for (int nivel = 1; nivel <= altura; nivel++) {
    imprimir_nivel( arbol, nivel, visit);
  }
}