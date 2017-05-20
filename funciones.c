#include <stdlib.h>
#include <stdio.h>
#include "listaen.c"

int juntar(tLista *l){

	int comienzo1 = getValue(l).comienzo;
	int final1 = getValue(l).final;
	next(l);
	int comienzo2 = getValue(l).comienzo;
	int final2 = getValue(l).final;
	prev(l);

	if (final1 == comienzo2-1)
	{
		elemento e0;
		e0.comienzo = comienzo1;
		e0.final = final2;

		lremove(l);

		modificarC(l,e0.comienzo);	
		return 0;
	}
	return 1;

}

void check(tLista *l)
{
	moveToStart(l);
	while(currPos(l) < length(l)-1)
	{
		if(juntar(l)!=0)next(l);
	}

}

int Malloc(tLista *lista1,tLista *lista2, int byte){
  int k,n,m;
  elemento a,b;
  for(moveToStart(lista1);currPos(lista1) < length(lista1); next(lista1)){
    a = getValue(lista1);
    n = a.comienzo;
    m = a.final;
    k = m - n + 1;
    if (byte == k){
      append(lista2,a);
      lremove(lista1);
      return 0;
    }
    else if ( byte < k){
      b.final = a.final;
      a.final = a.comienzo + byte - 1;
      b.comienzo = a.comienzo + byte;
      append(lista2, a);
      lremove(lista1);
      insert(lista1, b);


      return 0;
    }
  }
  return -1;
}

int main(){
	
	elemento e1;

	e1.comienzo =1;
	e1.final = 1000;

	tLista *l1 = crearLista();
	tLista *l2 = crearLista();
	append(l1,e1);
	
	Print(l1);
	Print(l2);
	
	Malloc(l1,l2,100);
	Print(l1);
	Print(l2);

	Malloc(l1,l2,100);
	Print(l1);
	Print(l2);
	Malloc(l1,l2,100);
	Print(l1);
	Print(l2);
	Malloc(l1,l2,700);
	Print(l1);
	Print(l2);
	return 0;
}
