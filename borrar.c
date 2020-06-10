#include "borrar.h"
#include "itree.h"
#include <stdio.h>
#include <stdlib.h>

void auxiliar_eliminar (AVL** arbol, int* buscar, AVL** sucesor) {
  AVL* aux = *sucesor;
  if ((*arbol)->izq == NULL && (*arbol)->der == NULL) { //Nodo hoja
    if (*buscar) *sucesor = *arbol;
    *arbol = NULL;
  } else if ((*arbol)->der == NULL) { //Hijo izquierdo
    if (*buscar) *sucesor = *arbol;
    *arbol = (*arbol)->izq;
    (*arbol)->extremo = (*arbol)->dato->b;
    (*arbol)->FB = 0;
  } else { //Hijo derecho
    if (*buscar) {
      *sucesor = (*arbol)->der;
      (*arbol)->der = NULL;
    } else {
      *arbol = (*arbol)->der;
    }
    (*arbol)->extremo = (*arbol)->dato->b;
    (*arbol)->FB = 0;
  }
  if (*buscar) {
    (*sucesor)->FB = aux->FB;
    (*sucesor)->der = aux->der;
    (*sucesor)->izq = aux->izq;
  }
}

void eliminar (AVL** arbol, Intervalo* intervalo, int* disminuyo, int* buscar,
  AVL** sucesor) {
  if (*arbol != NULL) {
    if (intervalo_igual ((*arbol)->dato, intervalo) && !(*buscar)) {
      AVL* borrar = *arbol;
      if (((*arbol)->izq != NULL && (*arbol)->der != NULL)) {
        *buscar = 1; // Busca sucesor
        eliminar (arbol, intervalo, disminuyo, buscar, arbol);
        (*arbol)->izq = borrar->izq;
        if ((*arbol)->izq != NULL) actualizar_extremo (*arbol, (*arbol)->izq);
        if ((*arbol)->der != NULL) actualizar_extremo (*arbol, (*arbol)->der);
      } else {
        auxiliar_eliminar (arbol, buscar, sucesor); // Elimina el nodo
        *disminuyo = 1;
      }
      free (borrar->dato);
      free (borrar);
    } else if (((*arbol)->izq == NULL || (*arbol)->der == NULL) && *buscar) {
      auxiliar_eliminar (arbol, buscar, sucesor); //Elimina el sucesor
      *disminuyo = 1;
    } else { // busca el nodo
      if (lexicografico(*arbol, intervalo) >= 0) { // busca izquierda
        eliminar (&(*arbol)->izq, intervalo, disminuyo, buscar, sucesor);
        if ((*arbol)->izq != NULL) actualizar_extremo (*arbol, (*arbol)->izq);
        if (*disminuyo) { //Balancea
          switch ((*arbol)->FB) {
            case -1:
              if ((*arbol)->der->FB == 1 || (*arbol)->der->FB == 0) {
                rotacion_dobleRL (arbol);
              } else {
                rotacion_simpleL (arbol);
              }
              *disminuyo = 1;
            break;
            case 0:
              (*arbol)->FB = -1;
              *disminuyo = 0;
            break;
            case 1:
              (*arbol)->FB = 0;
              *disminuyo = 1;
            break;
          }
        } // Fin balance
      } else { // busca en el hijo derecho
        eliminar (&(*arbol)->der, intervalo, disminuyo, buscar, sucesor);
        if ((*arbol)->der != NULL) actualizar_extremo (*arbol, (*arbol)->der);
        if (*disminuyo) { //Balancea
          switch ((*arbol)->FB) {
          case -1:
            (*arbol)->FB = 0;
            *disminuyo = 1;
          break;
          case 0:
            (*arbol)->FB = 1;
            *disminuyo = 0;
          break;
          case 1:
            if ((*arbol)->izq->FB == 1 || (*arbol)->izq->FB == 0) {
              rotacion_simpleR (arbol);
            } else {
              rotacion_dobleLR (arbol);
            }
            *disminuyo = 1;
          break;
          }
        } // Fin balance
      }
    }
  } else {
    printf("No se encontro el intervalo\n");
  }
}

void itree_eliminar (AVL** arbol, Intervalo* intervalo) {
  int disminuyo, buscar = 0;
  AVL* sucesor;
  eliminar (arbol, intervalo, &disminuyo, &buscar, &sucesor);
}
