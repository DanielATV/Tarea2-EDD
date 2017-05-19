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
		return 1; //Retorna 1 si falla.
	}
	l->curr->sig->info = item;
	l->curr->sig->sig = aux;
	if(l->curr == l->tail) l->tail = l->curr->sig;
	l->listSize++;
	return 0; //La operacion ocurrio con exito
}
//funciona
int append(tLista *l, elemento item)
{
	tNodo *temp = (tNodo*)malloc(sizeof(tNodo));
	if (temp==NULL) return 1;
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
		l->listSize++;
		return 0;
}
//funciona
elemento lremove(tLista *l){
	tNodo *aux = l->curr->sig;
	elemento item = l->curr->sig->info;

	l->curr->sig = l->curr->sig->sig;
	free((void *)aux);
	if (l->curr->sig == NULL){ 
		prev(l);
		l->pos --;
	}
	l->listSize--;
	return item;	
}
//funciona
void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head;

}
//funciona
void prev (tLista* l){
	
	tNodo *aux = l->head;
	
	while(aux->sig != l->curr){
		aux = aux->sig;
	
	}
	l->curr = aux;
	l->pos = (l->pos)-1;


}
//funciona
void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;
	prev(l);
}
//funciona
int next(tLista *l)
{	
	if(l->curr->sig != l->tail) 
	{
		l->curr = l->curr->sig;
		l->pos++;
		return 0;
	}
	else	return 1;
}
//funciona
int length(tLista *l){
	return l->listSize;
}
//funciona
int currPos(tLista *l)
{	
	return l->pos;
}
//funciona
elemento getValue(tLista *l){
	return l->curr->sig->info;
}
//funciona
void Print(tLista *L)
{
	printf("La lista es:");
	tNodo *temp2= L->head->sig;
		

	while(temp2 != NULL)
	{
		printf("[%d,%d] ",temp2->info.comienzo,temp2->info.final);
		temp2 = temp2->sig; 
	}	

	printf("\n");


}
//funciona
void Printelemento(elemento e)
{
	printf("el elemento es:");
	printf("[%d,%d] ",e.comienzo,e.final);
	printf("\n");


}
//funciona
void modificarC(tLista *l,int i){
	l->curr->sig->info.comienzo = i;
}
//funciona
void modificarF(tLista *l,int i){
	l->curr->sig->info.final = i;
}
