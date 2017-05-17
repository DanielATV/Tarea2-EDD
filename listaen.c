#include "lista_en.h"

tLista *crearLista()
{
	tLista *nueva = (tLista *) malloc(sizeof(tLista));
	nueva->head = NULL;
	nueva->tail = NULL;
	nueva->siese = 0;
	return nueva;
}

int insert(elemento item){
	tNodo *aux = curr->sig;
	curr->sig = (tNodo*)malloc(sizeof(tNodo));
	if (curr->sig == NULL){
		curr->sig = aux;
		return 0; //Retorna 0 si falla.
	}
	curr->sig->info = item;
	curr->sig->sig = aux;
	if(curr == tail) tail = curr->sig;
	listSize++;
	return 1; //La operacion ocurrio con exito
}
