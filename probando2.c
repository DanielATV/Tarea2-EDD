#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node{
	int datos[2];
	struct Node* next;
}Node;

typedef struct Lista{

	struct Node* primero;
	struct Node* actual;
	struct Node* ultimo;
	unsigned int largo;
	unsigned int pos;



	tLista *crearLista()
	{
		Lista *nueva = (Lista*)malloc(sizeof(struct Lista));
		nueva->primero= NULL;	
		nueva->ultimo =NULL;
		nueva->actual =NULL;
		nueva->largo = 0;
		return nueva;
	}



	void append( int x, int y)
	{
		struct Node *temp = (Node*)malloc(sizeof(struct Node));
		//(*temp).data = x;
		temp->datos[0] = x;
		temp->datos[1] = y;
	
		temp->next = NULL;
		if (head == NULL) head = temp;
		else
		{
			Node *temp2= head;
			while(temp2->next!=NULL)
			{
				temp2=temp2->next;

			}
			temp2->next = temp;

		}

	
	}





	void Print()
	{
		Node *temp2= head;
		printf("List is: ");

		while(temp2 != NULL)
		{
			printf("[%d,%d] ",temp2->datos[0],temp2->datos[1]);
			temp2 = temp2->next;  //aqui cambiar a actual...
		}	

		printf("\n");
	}

}tLista;

int main(int argv, char *argc[]){

	Lista *l = crearLista();
	
	append(2,1);
	append(3,2);
	append(4,1);
	append(5,2);
	Print();




	
	
}
