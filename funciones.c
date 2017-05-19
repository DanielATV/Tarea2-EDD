#include <stdlib.h>
#include <stdio.h>
#include "listaen.c"

elemento nextValue(tLista *l){
	return l->curr->sig->sig->info;
}

int juntar(tLista *l){

	int comienzo1 = getValue(l).comienzo;
	int final1 = getValue(l).final;

	int comienzo2 = nextValue(l).comienzo;
	int final2 = nextValue(l).final;

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

void juntartodas(tLista *l)
{
	moveToStart(l);
	while(currPos(l) < length(l)-1)
	{
		if(juntar(l)!=0)next(l);
		Print(l);
	}

}
