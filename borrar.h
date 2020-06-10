#ifndef _BORRAR_H_
#define _BORRAR_H_
#include "rotaciones.h"

void auxiliar_eliminar(AVL** arbol, int* buscar, AVL** sucesor);

void eliminar (AVL** arbol, Intervalo* intervalo, int* disminuyo, int* buscar, AVL** sucesor);

//Eliminar nodo del arbol
void itree_eliminar ( AVL** arbol, Intervalo* intervalo);



#endif //_BORRAR_H_