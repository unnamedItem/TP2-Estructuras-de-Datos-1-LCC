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

  if ( arbol == NULL ) {
    AVL *nuevoAVL = malloc( sizeof( AVL ) );
    nuevoAVL->dato == intervalo;
    nuevoAVL->extremo = intervalo->b;
    nuevoAVL->der == NULL;
    nuevoAVL->izq == NULL;
    nuevoAVL->FB == 0;
    arbol = nuevoAVL;
  }

  else {

    if ( intervalo->a < arbol->dato->a) {
      itree_insertar( intervalo, arbol->izq );
    }

    //else 
  
  }
  
}

int intervalo_igual(Intervalo *intervalo1, Intervalo *intervalo2) {
  if ( ( intervalo1->a == intervalo2->a ) && ( intervalo1->b == intervalo2->b ) ) return 1;
  else return 0;
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

int itree_balance_factor( AVL *arbol) {
  return itree_altura( arbol->izq ) - itree_altura( arbol->der );
}

void itree_destruir( AVL* arbol ) {
  if ( arbol != NULL) {
    itree_destruir(arbol->izq);
    itree_destruir(arbol->der);
    free( arbol );
  }
}

AVL* itree_intersecar( Intervalo* intervalo, AVL* arbol )  {

  if ( intersecta( intervalo, arbol->dato) ) return arbol;

  else if ( intervalo->b <= arbol->extremo ) itree_intersecar( intervalo, arbol->izq);
  
  else itree_intersecar( intervalo, arbol->der);
}