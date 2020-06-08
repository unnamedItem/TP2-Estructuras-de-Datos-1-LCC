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

void imprimir_nivel( AVL* arbol, int nivel, FuncionVisitante visit) {
  //nivel es asignado en recorrer bfs
  if ( arbol == NULL) // si no hay nodo no hace nada
        return; 
  else if ( nivel == 1) {
    visit( arbol->dato); // si nivel == 1 imprime el nivel
  }
  else if ( nivel > 1)
    imprimir_nivel( arbol->izq, nivel-1, visit );
    imprimir_nivel( arbol->der, nivel-1, visit );
}

void itree_recorrer_bfs( AVL *arbol, FuncionVisitante visit ) {
  int altura = itree_altura( arbol);
  for (int nivel = 1; nivel <= altura; nivel++) {
    imprimir_nivel( arbol, nivel, visit);
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
  
  if ( intervalo->a > arbol->extremo ) return NULL;

  else if ( intersecta( intervalo, arbol->dato) ) return arbol;

  else if ( intervalo->b <= arbol->dato->a ) itree_intersecar( intervalo, arbol->izq);
  
  else itree_intersecar( intervalo, arbol->der);
}

AVL* itree_buscar( Intervalo* intervalo, AVL* arbol ) {

  if ( intervalo->a > arbol->extremo ) return NULL;

  else if ( intervalo_igual( intervalo, arbol->dato )  ) return intervalo;
}
