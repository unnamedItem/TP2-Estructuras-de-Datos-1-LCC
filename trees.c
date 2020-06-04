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

void mostrar_intervalo (Intervalo intervalo) {
  printf("[%lf, %lf]\n", intervalo->a, intervalo->b);
}

/*
Verifica si los intervalos [a1, b1] y [a2, b2] se intersectan
*/
int intersecta (Intervalo inter1, Intervalo inter2) {
  if (inter1->a < inter2->b && inter1->b > inter2->a) return 1;
  return 0;
}

void itree_recorrer_dfs (AVL *arbol) {
  if (arbol == NULL) return;

  itree_recorrer_dfs (arbol->izq);

  mostrar_intervalo (arbol->dato);

  itree_recorrer_dfs (arbol->der);
}

void rotacion_simpleL (AVL* arbol) {
  AVL* aux = arbol->izq->der;
  arbol->izq->der = arbol;
  arbol->izq->FB = 0;
  AVL* aux2 = arbol->izq;
  arbol->izq = aux;
  arbol->FB = 0;
  arbol = aux2;
}

void rotacion_simpleR (AVL* arbol) {
  AVL* aux = arbol->der->izq;
  arbol->der->izq = arbol;
  arbol->izq->FB = 0;
  AVL* aux2 = arbol->der;
  arbol->der = aux;
  arbol->FB = 0;
  arbol = aux2;
}

void rotacion_dobleL (AVL* arbol) {
  rotacion_simpleR (arbol->izq);
  rotacion_simpleL (arbol);
}

void rotacion_dobleR (AVL* arbol) {
  rotacion_simpleL (arbol->der);
  rotacion_simpleR (arbol);
}

void insertar (AVL* arbol, int* aumento, Intervalo* intervalo) {
  if (arbol == NULL) {
    arbol = malloc(sizeof(AVL));
    arbol->dato = intervalo;
    arbol->izq = NULL;
    arbol->der = NULL;
    arbol->FB = 0;
    arbol->extremo = intervalo->b;
    aumento = 1;
  } else {
    if (intervalo->a < arbol->dato->a) {
      insertar (arbol->izq, aumento, intervalo);
      if (aumento) {
        switch (arbol->FB) {
          case -1:
            arbol->FB = 0;
            aumento = 0;
          break;
          case 0:
            arbol->FB = 1;
            aumento = 1;
          break;
          case 1:
            if (arbol->izq->FB == 1) {
              rotacion_simpleL (arbol);
            } else {
              rotacion_dobleL (arbol);
            }
          break;
        }
      }
    } else {
      insertar (arbol->der, aumento, intervalo);
      if (aumento) {
        switch (arbol->FB) {
          case -1:
            if (arbol->der->FB == 1) {
              rotacion_dobleR (arbol);
            } else {
              rotacion_simpleR (arbol);
            }
          break;
          case 0:
            arbol->FB = -1;
            aumento = 1;
          break;
          case 1:
            arbol->FB = 0;
            aumento = 0;
          break;
        }
      }
    }
  }
}

void itree_insertar (AVL* arbol, Intervalo* intervalo) {
  int aumento;
  insertar (arbol, aumento, intervalo);
}
