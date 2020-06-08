#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

void actualizar_extremo (AVL* nodo1, AVL* nodo2) {
  if (nodo1->extremo < nodo2->extremo)
    nodo1->extremo = nodo2->extremo;
}

void actualizar_rotacion_derecha (AVL* nodo1, AVL* nodo2 ) {
  if (nodo2->extremo <= nodo1->extremo) {
    nodo2->extremo = nodo2->dato->b; //Nodo 1 no posee el maximo extremo del sub arbol
    if (nodo2->der != NULL) {
      actualizar_extremo (nodo2, nodo2->der);
      if (nodo2->der->extremo == nodo1->extremo)
        return; //Todos los extremos son correctos
    actualizar_extremo (nodo2, nodo2->izq);
    return; // Nodo 1 posee el maximo del sub arbol
    }
  }
  actualizar_extremo (nodo1, nodo2); // Nodo 2 posee el maximo
}

void actualizar_rotacion_izquierda (AVL* nodo1, AVL* nodo2) {
  if (nodo2->extremo <= nodo1->extremo) {
    nodo2->extremo = nodo2->dato->b; //Nodo 1 no posee el maximo del sub arbol
    if (nodo2->izq != NULL) {
      actualizar_extremo (nodo2, nodo2->izq);
      if (nodo2->izq->extremo == nodo1->extremo)
        return; //Todos los nodos son correctos
    actualizar_extremo (nodo2, nodo2->der);
    return; // Nodo 1 posee el maximo del sub arbol
    }
  }
  actualizar_extremo (nodo1, nodo2); // Nodo 2 posee el maximo
}


void rotacion_simpleL (AVL** arbol) {
  //arbol = nodo desbalanceado, Rotacion a derecha
  AVL* aux = (*arbol)->izq->der; // E = hijo derecho del sub-arbol izq del nodo desbalanceado
  (*arbol)->izq->der = (*arbol); // Nodo desbalanceado esta donde estaba E, es decir la rotacion
  (*arbol)->izq->FB = 0; // sub-arbol balanceado
  AVL* aux2 = (*arbol)->izq; // D = hijo izq del nodo desbalanceado
  (*arbol)->izq = aux; // izq del nodo desbalanceado (ahora hijo), es ahora E
  (*arbol)->FB = 0;
  *arbol = aux2; // Nodo desbalanceado pasa a ser su hijo izq, termina la rotacion
  actualizar_rotacion_izquierda ((*arbol), (*arbol)->der);
}

void rotacion_simpleR (AVL** arbol) {
  //arbol = B = Nodo desbalanceado, rotacion a izquierda
  AVL* aux = (*arbol)->der->izq; // C = sub-arbol izq del hijo derecho del arbol
  (*arbol)->der->izq = (*arbol); // Reemplazo el sub-arbol izquierdo del hijo der del nodo desbalanceado por B
  // es decir, "bajo la raiz"
  (*arbol)->der->FB = 0;
  AVL* aux2 = (*arbol)->der; // D = Hijo derecho del arbol
  (*arbol)->der = aux; // La derecha de B apunta C
  (*arbol)->FB = 0;
  *arbol = aux2; // D se convierte en la raiz del arbol desbalanceado, "subo el hijo derecho" 
  actualizar_rotacion_derecha ((*arbol), (*arbol)->izq);
}

void rotacion_dobleL (AVL** arbol) {
  //rotacion izquierda derecha
  //Desbalance en el hijo derecho del hijo izquierdo de la raiz.
  rotacion_simpleR (&(*arbol)->izq);
  actualizar_extremo ((*arbol), (*arbol)->izq);
  rotacion_simpleL (arbol);
}

void rotacion_dobleR (AVL** arbol) {
  //Rotacion Derecha izquierda
  // Desbalance en el hijo izquierdo del hijo derecho de la raiz.
  //arbol nodo desbalanceado
  rotacion_simpleL (&(*arbol)->der); // bajo un nivel
  actualizar_extremo ((*arbol), (*arbol)->der);
  rotacion_simpleR (arbol);
}

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
              rotacion_simpleL (arbol);
            } else {
              rotacion_dobleL (arbol);
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
              rotacion_dobleR (arbol);
            } else {
              rotacion_simpleR (arbol);
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