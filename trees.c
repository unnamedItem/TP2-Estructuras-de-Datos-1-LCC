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

