#include <stdlib.h>
#include <stdio.h>

typedef struct elemento{
 int comienzo;
 int final;
} elemento;

typedef struct nodo {
 elemento *info; // el elemento en sí
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

tLista *crearLista(){
	tLista* nueva = (tLista *) malloc(sizeof(tLista));
	/*tNodo* dummy = (tNodo *)malloc(sizeof(tNodo));
	dummy->sig = NULL;
	nueva->head = dummy;
	nueva->tail = NULL;
	nueva->curr = dummy;
	nueva->listSize = 0;
	nueva->pos = 0;
	*/
	nueva->head = NULL;
	nueva->tail = NULL;
	nueva->curr = NULL;
	nueva->listSize = 0;
	nueva->pos = 0;
	return nueva;
}

void append(tLista *l, elemento *item)
	{
		tNodo *temp = (tNodo*)malloc(sizeof(tNodo));
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

	
	}

/*
int append(tLista* l,elemento *item)
{
	tNodo *aux =(tNodo *)malloc(sizeof(tNodo));
	if(aux == NULL)
	{
	        return 0;
	}

	l->tail->sig =  aux;
	aux->info = item;
	aux->sig=NULL;

	

	
	
	
	
	
	l->tail =aux;
	free(aux);
	l->listSize++;
	return 1;
}
*/
/*
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
*/

void Print(tLista *L)
{
	printf("La lista es:");
	tNodo *temp2= L->head;
		printf("La lista es: ");

		while(temp2 != NULL)
		{
			printf("[%d,%d] ",temp2->info->comienzo,temp2->info->final);
			temp2 = temp2->sig; 
		}	

		printf("\n");


}

int main(){
	
 	elemento *e1 = (elemento*)malloc(sizeof(elemento));
	e1->comienzo =1;
	e1->final = 2;
	elemento *e2 = (elemento*)malloc(sizeof(elemento));
	e2->comienzo =3;
	e2->final = 5;
	
	tLista *l = crearLista();

	append(l,e1);
	free(e1);

	append(l,e2);
	free(e2);
	
	Print(l);
	free(l);
	
	return 0;
}



