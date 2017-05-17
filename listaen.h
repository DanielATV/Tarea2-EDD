#ifndef __lista_en_h__
#define __lista_en_h__

#include <stdlib.h>

typedef struct elemento{
 int comienzo;
 int final;
} elemento;

typedef struct nodo {
 elemento info; // el elemento en sí
 struct nodo *sig; // puntero autoreferencial
                   // al proximo nodo
} tNodo;

//Estructura de la lista:
typedef struct Lista{
 tNodo *head; //Primer elemento
 tNodo *tail; //Ultimo elemento
 tNodo *curr; //Elemento actual
 unsigned int listSize; //Tamaño de la lista
 unsigned int pos; // Posición actual en la lista
} tLista;


// crea la lista
tLista * crearLista();
// borra todos los elementos de la lista, reinicializándola vacía D
void clear (lista_t *);
// inserta un elemento en la posición actual de la lista S
int insert (tElemLista item);
// agrega un elemento al final de la lista ******
int append (tElemLista item);
// borra el elemento actual y retorna su valor  F
tElemLista remove ();
// mueve la posición actual al comienzo de la lista D
void moveToStart ();
// mueve la posición actual al final de la lista S 
void moveToEnd ();
// mueve la posición actual al siguiente elemento de la lista.
// No produce cambios si está en la cabeza de la lista F
void next ();
// mueve la posición actual al elemento anterior de la lista.
// No produce cambios si está en la cola de la lista D
void prev ();
// retorna el número de elementos en la lista s
int length ();
// retorna la posición del elemento actual F
int currPos ();
// mueve la posición actual a una especificada D
void moveToPos (int pos);
// obtiene el valor del elemento actual de la lista S
tElemLista getValue ();

#endif
