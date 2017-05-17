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
	struct tNodo *temp = (Node*)malloc(sizeof(struct Node));
	//(*temp).data = x;
	temp->info =item;
	
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;

	}
	else
	{
		tNodo *temp2= curr;
		while(temp2->sig!=NULL)
		{
			temp2=temp2->sig;

		}
		temp2->sig = temp;
		tail=temp;
	}
	listSize++;
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
