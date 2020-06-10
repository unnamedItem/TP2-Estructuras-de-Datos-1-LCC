#include "itree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int intervalo_igual(Intervalo *intervalo1, Intervalo *intervalo2) {
  if ( ( intervalo1->a == intervalo2->a ) && ( intervalo1->b == intervalo2->b ) ) return 1;
  else return 0;
}

void itree_destruir( AVL* arbol ) {
  if ( arbol != NULL) {
    itree_destruir(arbol->izq);
    itree_destruir(arbol->der);
    free( arbol->dato);
    free( arbol );
  }
}

AVL* itree_intersecar( Intervalo* intervalo, AVL* arbol )  {
  if ( arbol == NULL ) {
    printf("No\n");
    return NULL;
    }
  else if ( intervalo->a > arbol->extremo ) {
    printf("No\n");
    return NULL;
    }
  else if ( intersecta( intervalo, arbol->dato) ) {
    printf("Si, %lf %lf\n", arbol->dato->a, arbol->dato->b);
    return arbol;
    }
  else if ( intervalo->a > arbol->dato->b ) return itree_intersecar( intervalo, arbol->der);
  
  else return itree_intersecar( intervalo, arbol->izq);
}

