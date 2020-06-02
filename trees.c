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

//creo que esto anda, no estoy 100 por ciento seguro
int intersecta (Intervalo *intervalo1, Intervalo *intervalo2) {
   if(intervalo1->a <= intervalo2->b && intervalo2->a <= intervalo1->b) {
      return 1;
   }
   else return 0;
}

AVL* itree_crear () {
    return NULL;
}

