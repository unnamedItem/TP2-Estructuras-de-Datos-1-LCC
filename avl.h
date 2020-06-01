#ifndef AVL_H
#define AVL_H

typedef struct _Intervalo {
  double a, b; // [a, b] intervalo
  double extremo; // extremo maximo b
} Intervalo;

typedef struct _AVL {
  Intervalo *dato;
  int FB; /* factor de balance*/
  struct _AVL *izq, *der;
} AVL;

//==============================================================================

/*  Comprueba si dos intervalos se intersectan */
int intersecta (Intervalo *intervalo1, Intervalo *intervalo2);

//Reserva memoria para un intervalo
Intervalo* crear_intervalo (double a, double b);

//Crear arbol
AVL* itree_crear ();

//Insertar en el arbol
void itree_insertar (Intervalo* intervalo, AVL* arbol);

//Liberar el arbol
void itree_destruir (AVL* arbol);

//Eliminar nodo del arbol
AVL* itree_eliminar (Intervalo* intervalo, AVL* arbol);

//Recorrido en profundidad del arbol
void itree_recorrer_dfs (AVL* arbol);

//Recorrido a lo ancho del arbol
void itree_recorrer_bfs (AVL* arbol);

//Busqueda de interseccion de intervalos en el arbol
Intervalo* itree_intersectar (Intervalo* intervalo, AVL* arbol);

//Rotacion simple derecha
void rotacion_simpleR (AVL* arbol);

//Rotacion simple izquierda
void rotacion_simpleL (AVL* arbol);

//Rotacion doble derecha
void rotacion_dobleR (AVL* arbol);

//Rotacion doble izquierda
void rotacion_dobleL (AVL* arbol);

#endif /* AVL_H */
