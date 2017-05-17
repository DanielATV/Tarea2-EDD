#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node{
	int datos[2];
	struct Node* next;
}Node;

struct Node* head;
struct Node* actual;  //hay que usar esto
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
	//struct Node* temp=head;
	printf("List is: ");

	while(head != NULL)
	{
		printf("[%d,%d] ",head->datos[0],head->datos[1]);
		head = head->next;  //aqui cambiar a actual...
	}	

	printf("\n");
}


int main(int argv, char *argc[]){

//Para insert y print
	//Node* head = NULL;
	append(2,1);
	append(3,2);
	append(4,1);
	append(5,2);
	Print();




	/*
	//Node* head = NULL;
	printf("How many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i; i<n;i++){
		printf("Enter the number \n");
		scanf("%d",&x);
		head = Insert0(head,x);
		Print(head);
	}

	*/
	
}
