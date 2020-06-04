#ifndef AVL_H
#define AVL_H

typedef struct _Intervalo {
  double a, b; // [a, b] intervalo
} Intervalo;

typedef void (*FuncionVisitante) (Intervalo* intervalo);


typedef struct _AVL {
  Intervalo *dato;
  int FB; /* factor de balance*/
  double extremo; // extremo maximo b
  struct _AVL *izq, *der;
} AVL;

//==============================================================================

/*  Comprueba si dos intervalos se intersectan */
int intersecta (Intervalo *intervalo1, Intervalo *intervalo2);

//Reserva memoria para un intervalo
Intervalo* crear_intervalo (double a, double b);

//Crear arbol
AVL* itree_crear ();

//Muestra el intervalo en terminal
<<<<<<< HEAD
void mostrar_intervalo (Intervalo intervalo);
=======
void mostrar_intervalo (Intervalo* intervalo);
>>>>>>> 85c834c40a4942e33b1e6220ef4d06533f5007b1

//Funcion auxiliar de itree_insertar
void insertar (AVL *arbol, int* aumento, Intervalo *intervalo);

//Insertar en el arbol
void itree_insertar (Intervalo* intervalo, AVL* arbol);

//Liberar el arbol
void itree_destruir (AVL* arbol);

//Eliminar nodo del arbol
AVL* itree_eliminar (Intervalo* intervalo, AVL* arbol);

//Recorrido en profundidad del arbol
void itree_recorrer_dfs (AVL* arbol, FuncionVisitante funcion);

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

#endif
