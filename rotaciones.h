#ifndef _ROTACIONES_H_
#define _ROTACIONES_H_
#include "estructuras.h"

void actualizar_extremo (AVL* nodo1, AVL* nodo2);

void actualizar_rotacion_izquierda (AVL* nodo1 , AVL* nodo2 );

void actualizar_rotacion_derecha (AVL* nodo1, AVL* nodo2);

void rotacion_simpleR (AVL** arbol);

void rotacion_simpleL (AVL** arbol);

void rotacion_dobleLR (AVL** arbol);

void rotacion_dobleRL (AVL** arbol);

int lexicografico (AVL* arbol, Intervalo* intervalo);

#endif //_ROTACIONES_H_