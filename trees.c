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

/*
Verifica si los intervalos [a1, b1] y [a2, b2] se intersectan
*/
int intersecta (Intervalo inter1, Intervalo inter2) {
  if (inter1->a < inter2->b && inter1->b > inter2->a) return 1;
  return 0;
}
