#include "listaen.h"
#include <stdlib.h>
#include <stdio.h>

//funciona
tLista *crearLista(){
	tLista* nueva = (tLista *) malloc(sizeof(tLista));
	tNodo* dummy = (tNodo *)malloc(sizeof(tNodo));
	dummy->sig = NULL;
	nueva->head = dummy;
	nueva->tail = dummy;
	nueva->curr = dummy;
	nueva->listSize = 0;
	nueva->pos = 0;
	return nueva;
}
//funciona
int insert(tLista *l, elemento item){
	tNodo *aux = l->curr->sig;
	l->curr->sig = (tNodo *)malloc(sizeof(tNodo));
	if (l->curr->sig == NULL){
		l->curr->sig = aux;
		return 0; //Retorna 0 si falla.
	}
	l->curr->sig->info = item;
	l->curr->sig->sig = aux;
	if(l->curr == l->tail) l->tail = l->curr->sig;
	l->listSize++;
	return 1; //La operacion ocurrio con exito
}
//funciona
int append(tLista *l, elemento item)
{
	tNodo *temp = (tNodo*)malloc(sizeof(tNodo));
	if (temp==NULL) return 0;
	else		
	//(*temp).data = x;
	temp->info = item;


	temp->sig = NULL;
	if (l->head == NULL) l->head = temp;
	else
	{
		tNodo *temp2= l->head;
		while(temp2->sig!=NULL)
		{
			temp2=temp2->sig;

		}
		temp2->sig = temp;

	}
	return 1;


}


elemento lremove(tLista *l){
	int i;	
	tNodo *aux = l->curr->sig;
	elemento item = l->curr->sig->info;

	l->curr->sig = l->curr->sig->sig;
	free((void *)aux);

	l->listSize--;
	return item;	
}

void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head -> sig;

}

void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;	
}

void prev (tLista* l){
	int aux,i;
	aux = l -> pos;
	moveToStart(l);
	for (i = 0; i<aux; i++){
		curr = l->curr;
		next(l);
	}
	l -> pos = aux - 1;
}

void next(tLista *l)
{	
	if(l->curr->sig != l->tail) 
	{
		l->curr = l->curr->sig;
		l->pos++;
		
	}
}

int lenght(tLista *l){
	return l->listSize;
}

int currPos(tLista *l)
{	
	return l->pos;
}

//funciona
elemento getValue(tLista *l){
	return l->curr->sig->info;
}
