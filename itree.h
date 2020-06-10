#ifndef _ITREE_H
#define _ITREE_H
#include "estructuras.h"

//Reserva memoria para un intervalo
Intervalo* crear_intervalo (double a, double b);

//Crear arbol
AVL* itree_crear ();

//Muestra el intervalo en terminal
void mostrar_intervalo (Intervalo* intervalo);

/*  Comprueba si dos intervalos se intersectan */
int intersecta (Intervalo *intervalo1, Intervalo *intervalo2);

//Retorna 1 si dos intervalos son iguale, 0 si no.
int intervalo_igual(Intervalo *intervalo1, Intervalo *intervalo2);

//Liberar el arbol
void itree_destruir (AVL* arbol);

//Busqueda de interseccion de intervalos en el arbol
AVL* itree_intersecar (Intervalo* intervalo, AVL* arbol);


#endif //_ITREE_H