#ifndef _RECORRER_H_
#define _RECORRER_H_
#include "estructuras.h"

//Recorrido en profundidad del arbol
void itree_recorrer_dfs (AVL* arbol, FuncionVisitante funcion);

//devuelve la altura de un arbol
int itree_altura( AVL* arbol );

//Funcion auxiliar de recorrer bfs
void imprimir_nivel( AVL* arbol, int nivel, FuncionVisitante visit);

//Recorrido a lo ancho del arbol
void itree_recorrer_bfs (AVL* arbol, FuncionVisitante visit);

#endif // _RECORRER_H_
