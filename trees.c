#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

Intervalo* crear_intervalo (double a, double b) {
    Intervalo *nuevoIntervalo = malloc(sizeof( Intervalo) );
    nuevoIntervalo->a =a ;
    nuevoIntervalo->b = b;
    return nuevoIntervalo;
};


AVL* itree_crear () {
    return NULL;
}

void mostrar_intervalo (Intervalo* intervalo) {
  printf("[%lf, %lf]\n", intervalo->a, intervalo->b);
}

/*
Verifica si los intervalos [a1, b1] y [a2, b2] se intersectan
*/
int intersecta (Intervalo *inter1, Intervalo *inter2) {
  if (inter1->a < inter2->b && inter1->b > inter2->a) return 1;
  return 0;
}

/*inorder*/
void itree_recorrer_dfs (AVL *arbol, FuncionVisitante visit) {
  if (arbol == NULL) return;

  itree_recorrer_dfs (arbol->izq, visit);

  visit (arbol->dato);

  itree_recorrer_dfs (arbol->der, visit);
}

void itree_insertar( Intervalo *intervalo, AVL *arbol  ) {
  AVL *nuevoAVL = malloc( sizeof( AVL ) );
  nuevoAVL->dato == intervalo;
  nuevoAVL->der == NULL;
  nuevoAVL->izq == NULL;
  nuevoAVL->extremo // ???
  if ( arbol == NULL ) {
    
  }
}

