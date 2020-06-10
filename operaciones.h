#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_
#include "rotaciones.h"


int lexicografico (AVL* arbol, Intervalo* intervalo);

void insertar (AVL** arbol, int* aumento, Intervalo* intervalo);

//Insertar en el arbol
void itree_insertar ( AVL** arbol, Intervalo* intervalo);

void borrar (AVL** arbol,  Intervalo* intervalo);

//Eliminar nodo del arbol
AVL* itree_eliminar (Intervalo* intervalo, AVL** arbol);

#endif //_OPERACIONES_H_