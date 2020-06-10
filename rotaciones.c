#include <stdio.h>
#include <stdlib.h>
#include "rotaciones.h"

void actualizar_extremo (AVL* nodo1, AVL* nodo2) {
  if (nodo1->extremo < nodo2->extremo)
    nodo1->extremo = nodo2->extremo;
}

void actualizar_rotacion_izquierda(AVL* nodo1 , AVL* nodo2 ) {
  //nodo1 nodo "nueva raiz  " nodo2 "nodo rotado"
  if (nodo2->extremo <= nodo1->extremo) {
    nodo2->extremo = nodo2->dato->b; //Nodo 1 no posee el maximo extremo del sub arbol
    if (nodo2->der != NULL) { // Se utiliza en las rotaciones dobles, cuando un nodo cambia de sub-arbol y este tiene un nuevo cambio
      actualizar_extremo (nodo2, nodo2->der); //verifica que tenga el extremo correcto
    actualizar_extremo (nodo2, nodo2->izq); //verifica el otro nodo
    }
  }
  actualizar_extremo (nodo1, nodo2); // Actualiza la "raiz", Nodo 2 posee el maximo
}

void actualizar_rotacion_derecha (AVL* nodo1, AVL* nodo2) {
//nodo1 nodo "nueva raiz  " nodo2 "nodo rotado"
  if (nodo2->extremo <= nodo1->extremo) {
    nodo2->extremo = nodo2->dato->b; //Nodo 1 no posee el maximo del sub arbol
    if (nodo2->izq != NULL) {
      actualizar_extremo (nodo2, nodo2->izq); //
    actualizar_extremo (nodo2, nodo2->der);
    }
  }
  actualizar_extremo (nodo1, nodo2); // Nodo 2 posee el maximo
}


void rotacion_simpleR (AVL** arbol) {
  //arbol = nodo desbalanceado, Rotacion a derecha
  AVL* aux = (*arbol)->izq->der; // E = hijo derecho del sub-arbol izq del nodo desbalanceado
  (*arbol)->izq->der = (*arbol); // Nodo desbalanceado esta donde estaba E, es decir la rotacion
  (*arbol)->izq->FB = 0; // sub-arbol balanceado
  AVL* aux2 = (*arbol)->izq; // D = hijo izq del nodo desbalanceado
  (*arbol)->izq = aux; // izq del nodo desbalanceado (ahora hijo), es ahora E
  (*arbol)->FB = 0;
  *arbol = aux2; // Nodo desbalanceado pasa a ser su hijo izq, termina la rotacion
  actualizar_rotacion_derecha ((*arbol), (*arbol)->der);
}

void rotacion_simpleL (AVL** arbol) {
  //arbol = B = Nodo desbalanceado, rotacion a izquierda
  AVL* aux = (*arbol)->der->izq; // C = sub-arbol izq del hijo derecho del arbol
  (*arbol)->der->izq = (*arbol); // Reemplazo el sub-arbol izquierdo del hijo der del nodo desbalanceado por B
  // es decir, "bajo la raiz"
  (*arbol)->der->FB = 0;
  AVL* aux2 = (*arbol)->der; // D = Hijo derecho del arbol
  (*arbol)->der = aux; // La derecha de B apunta C
  (*arbol)->FB = 0;
  *arbol = aux2; // D se convierte en la raiz del arbol desbalanceado, "subo el hijo derecho" 
  actualizar_rotacion_izquierda ((*arbol), (*arbol)->izq);
}

void rotacion_dobleLR (AVL** arbol) {
  //rotacion izquierda derecha
  //Desbalance en el hijo derecho del hijo izquierdo de la raiz.
  rotacion_simpleL (&(*arbol)->izq);
  actualizar_extremo ((*arbol), (*arbol)->izq);
  rotacion_simpleR (arbol);
}

void rotacion_dobleRL (AVL** arbol) {
  //Rotacion Derecha izquierda
  // Desbalance en el hijo izquierdo del hijo derecho de la raiz.
  //arbol nodo desbalanceado
  rotacion_simpleR (&(*arbol)->der); // bajo un nivel
  actualizar_extremo ((*arbol), (*arbol)->der);
  rotacion_simpleL (arbol);
}

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
