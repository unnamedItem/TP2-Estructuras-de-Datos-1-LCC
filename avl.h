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
void mostrar_intervalo (Intervalo* intervalo);

//Insertar en el arbol
void itree_insertar (Intervalo* intervalo, AVL* arbol);

//Liberar el arbol
void itree_destruir (AVL* arbol);

//Eliminar nodo del arbol
AVL* itree_eliminar (Intervalo* intervalo, AVL* arbol);

//Recorrido en profundidad del arbol
void itree_recorrer_dfs (AVL* arbol, FuncionVisitante funcion);

//Impresion recursiva de niveles de un arbol
void imprimir_nivel( AVL* arbol, int nivel, FuncionVisitante visit);

//Recorrido a lo ancho del arbol
void itree_recorrer_bfs (AVL* arbol, FuncionVisitante visit);

//Busqueda de interseccion de intervalos en el arbol
AVL* itree_intersecar (Intervalo* intervalo, AVL* arbol);

//Rotacion simple derecha
void rotacion_simpleR (AVL** arbol);

//Rotacion simple izquierda
void rotacion_simpleL (AVL** arbol);

//Rotacion doble derecha
void rotacion_dobleR (AVL** arbol);

//Rotacion doble izquierda
void rotacion_dobleL (AVL** arbol);

//Retorna 1 si dos intervalos son iguale, 0 si no.
int intervalo_igual(Intervalo *intervalo1, Intervalo *intervalo2);

//devuelve la altura de un arbol
int itree_altura( AVL* arbol );

//Regresa el factor balance de un arbol
int itree_balance_factor( AVL *arbol);
#endif
