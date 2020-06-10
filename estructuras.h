#ifndef _ESTRUCTURAS_H
#define _ESTRUCTURAS_H

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

#endif //_ESTRUCTURAS_H