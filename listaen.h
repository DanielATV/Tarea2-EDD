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

 // crea la lista LISTO
 tLista *crearLista();
 // borra todos los elementos de la lista, reinicializándola vacía D
 void clear (lLista*);
 // inserta un elemento en la posición actual de la lista S LISTO
 int insert (lLista*,elemento);
 // agrega un elemento al final de la lista LISTO
 int append (lLista*,tElemLista);
 // borra el elemento actual y retorna su valor  F LISTO
 elemento remove (lLista*);
 // mueve la posición actual al comienzo de la lista D
 void moveToStart (lLista*);
 // mueve la posición actual al final de la lista S LISTO
 void moveToEnd (lLista*);
 // mueve la posición actual al siguiente elemento de la lista.
 // No produce cambios si está en la cabeza de la lista F LISTO
 void next (lLista*);
 // mueve la posición actual al elemento anterior de la lista.
 // No produce cambios si está en la cola de la lista D
 void prev (lLista*);
 // retorna el número de elementos en la lista s LISTO
 int length (lLista*);
 // retorna la posición del elemento actual F LISTO
 int currPos (lLista*);
 // mueve la posición actual a una especificada D
 void moveToPos (lLista*,int);
 // obtiene el valor del elemento actual de la lista S LISTO
 tElemLista getValue (lLista*);

#endif
