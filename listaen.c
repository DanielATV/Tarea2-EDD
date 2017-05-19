#include "lista_en.h"

tLista *crearLista(){
	tLista* nueva = (tLista *) malloc(sizeof(tLista));
	tNodo* dummy = (tNodo *)malloc(sizeof(tNodo));
	nueva->head = dummy;
	dummy->sig = NULL;
	nueva->tail = NULL;
	nueva->curr = NULL;
	nueva->listSize = 0;
	nueva->pos = 0;
	return nueva;
}

int insert(elemento item){
	tNodo *aux = curr->sig;
	curr->sig = (tNodo *)malloc(sizeof(tNodo));
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

void movetoEnd(){
	for(pos; pos < listSize -1; pos++) curr = curr->sig;
  
//******************

void append(elemento item)
{
	tNodo *aux = l->tail->sig;
	l->tail->sig =  (tNodo *)malloc(sizeof(tNodo));
	if(l->tail->sig == NULL)
	{
	        return 0;
	}

	aux->info = item;
	aux->sig=NULL;
	l->tail = aux;
	l->listSize++;
	return 1;
}


tElemLista remove()
{	
	elemento item = curr->info;
	
	
	Node *temp = head;
	while(temp->sig!=curr)
	{
		temp = temp->sig;
		
	}	
	
	temp->sig = curr->sig;
	curr -> (temp->sig);
	listSize--;
	
	
	return info;	


}


void next()
{	
	if(curr != head) curr = curr->sig;
}

int currPos()
{	
	if (head ==curr) return 0;
	else
	{
		int pos=1;
		tNodo *temp = head;
		while (tNodo->sig != curr)	pos++;

		return pos;
	}
}
