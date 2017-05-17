#include "listaen.h"
#include <stdlib.h>
#include <stdio.h>

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

void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;	
}

int append(tLista *l,elemento item)
{
	struct tNodo *temp = (Node*)malloc(sizeof(struct Node));
	if (temp == NULL) 
	  {
	      printf("No hay suficiente memoria disponible \n");
	      return 0;
	   }
	//(*temp).data = x;
	temp->info =item;
	
	temp->next = NULL;
	if (l->head == NULL)
	{
		l->head = temp;
		l->tail = temp;

	}
	else
	{
		tNodo *temp2= l->curr;
		while(temp2->sig!=NULL)
		{
			temp2=temp2->sig;

		}
		temp2->sig = temp;
		l->tail=temp;
	}
	l->listSize++;
	return 1;
}


elemento remove(tLista *l)
{	
	elemento item = l->curr->info;
	
	
	Node *temp = l->head;
	while(temp->sig!=l->curr)
	{
		temp = temp->l->sig;
		
	}	
	
	temp->sig = l->curr->sig;
	l->curr -> (temp->sig);
	l->listSize--;
	
	
	return info;	


}


void next(tLista *l)
{	
	if(l->curr != l->tail) 
	{
		l->curr = l->curr->sig;
		l->pos++;
		
	}
}

int currPos(tLista *l)
{	
	return l->pos;
}

int lenght(tLista *l){
	return l->listSize;
}

elemento getValue(tLista *l){
	return l->curr->info;
}

void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head;

}
