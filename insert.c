#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

void insertar (AVL** arbol, int* aumento, Intervalo* intervalo) {
  
  if (*arbol == NULL) { //agrega el nodo
    *arbol = malloc(sizeof(AVL));
    (*arbol)->dato = intervalo;
    (*arbol)->izq = NULL;
    (*arbol)->der = NULL;
    (*arbol)->FB = 0;
    (*arbol)->extremo = intervalo->b;
    *aumento = 1;
   }

   else {
    if ( intervalo->a < (*arbol)->dato->a ) {
      insertar ( &(*arbol)->izq, aumento, intervalo );
      actualizar_extremo ( (*arbol), (*arbol)->izq );

      if ( aumento ) {

        switch ( (*arbol)->FB ) {
          case -1:
            (*arbol)->FB = 0;
            *aumento = 0;
          break;
          case 0:
            (*arbol)->FB = 1;
            *aumento = 1;
          break;
          case 1:
            if ((*arbol)->izq->FB == 1) {
              rotacion_simpleR (arbol);
            } else {
              rotacion_dobleLR (arbol);
            }
            *aumento = 1;
          break;
        }
      }
    }

     else {
      insertar (&(*arbol)->der, aumento, intervalo);
      actualizar_extremo ((*arbol), (*arbol)->der);

      if (aumento) {
          
        switch ((*arbol)->FB) {
          case -1:
            if ((*arbol)->der->FB == 1) {
              rotacion_dobleRL (arbol);
            } else {
              rotacion_simpleL (arbol);
            }
            *aumento = 1;
          break;
          case 0:
            (*arbol)->FB = -1;
            *aumento = 1;
          break;
          case 1:
            (*arbol)->FB = 0;
            *aumento = 0;
          break;
        }
      }
    }
  }
}

void itree_insertar (Intervalo* intervalo, AVL* arbol) {
    
}