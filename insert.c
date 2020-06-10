#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int lexicografico (AVL* arbol, Intervalo* intervalo) {
  if (intervalo->a < arbol->dato->a) {
    return 1; // Izquierda
  } else if (intervalo->a > arbol->dato->a) {
    return -1; // Derecha
  } else if (intervalo->b < arbol->dato->b) {
    return 1; // Izquierda
  } else if (intervalo->b > arbol->dato->b) {
    return -1; // Derecha
  } else { // Iguales
    return 0;
  }
}

void insertar (AVL** arbol, int* aumento, Intervalo* intervalo) {
  if (*arbol == NULL) { // Inserta el nodo
    *arbol = malloc(sizeof(AVL));
    (*arbol)->dato = intervalo;
    (*arbol)->izq = NULL;
    (*arbol)->der = NULL;
    (*arbol)->FB = 0;
    (*arbol)->extremo = intervalo->b;
    *aumento = 1;
  } else { // Busca el lugar correcto
    switch (lexicografico (*arbol, intervalo)) {
    case 1: // Izquierda
      insertar (&(*arbol)->izq, aumento, intervalo);
      actualizar_extremo ((*arbol), (*arbol)->izq);
      if (*aumento) { //Balancea
        switch ((*arbol)->FB) {
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
      } // Fin del balance
    break;
    case 0: // Iguales
      printf("Ya existe el intervalo en el arbol\n");
      *aumento = 0;
    break;
    case -1: // Derecha
      insertar (&(*arbol)->der, aumento, intervalo);
      actualizar_extremo ((*arbol), (*arbol)->der);
      if (*aumento) { //Balancea
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
      } // Fin del balance
    break;
    }
  }
}


void itree_insertar (AVL** arbol, Intervalo* intervalo) {
  int aumento;
  insertar (arbol, &aumento, intervalo);
}