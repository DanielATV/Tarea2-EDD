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
void clear (tLista*);
// inserta un elemento en la posición actual de la lista S LISTO
int insert (tLista*,elemento);
// agrega un elemento al final de la lista LISTO
int append (tLista*,elemento);
// borra el elemento actual y retorna su valor  F LISTO
elemento lremove (tLista*);
// mueve la posición actual al comienzo de la lista D LISTO
void moveToStart (tLista*);
// mueve la posición actual al final de la lista S LISTO
void moveToEnd (tLista*);
// mueve la posición actual al siguiente elemento de la lista.
// No produce cambios si está en la cabeza de la lista F LISTO
int next (tLista*);
// mueve la posición actual al elemento anterior de la lista.
// No produce cambios si está en la cola de la lista D LISTO
void prev (tLista*);
// retorna el número de elementos en la lista s LISTO
int length (tLista*);
// retorna la posición del elemento actual F LISTO
int currPos (tLista*);
// mueve la posición actual a una especificada D(puede no necesario)
void moveToPos (tLista*,int);
// obtiene el valor del elemento actual de la lista S LISTO
elemento getValue (tLista*);
// imprime la lista F
void Print(tLista *); 
// imprime un elemento F
void Printelemento(elemento);
// Resetea la Lista l
void clearL(tLista*);
#endif
