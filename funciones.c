void juntar(tLista *l){
	
	int comienzo1 = getValue(l).comienzo;
	int final1 = getValue(l).final;
	next(l);
	int comienzo2 = getValue(l).comienzo;
	int final2 = getValue(l).final;
	prev(l);
	printf("c1:%d,f1:%d,c2:%d,f2:%d",comienzo1,final1,comienzo2,final2);

	if (final1 == comienzo2-1)
	{
		elemento e0;
		e0.comienzo = comienzo1;
		e0.final = final2;
		//tNodo n0;
		//n0.info = e0;
		//n0.sig = l->curr->sig->sig;
		lremove(l);
		//insert(l,e0);
		//next(l);
		//next(l);
		lremove(l);
		insert(l,e0);	

	}

}

void juntartodas(tLista *l)
{
	moveToStart(l);
	while(next(l)==0)
	{
		while(juntar(l)==0)	juntar(l);
		next(l);
	}

}


int main(){
	
	elemento e1,e2,e3,e4,e5,e6,e7,e8,e9,e10;
	e1.comienzo =1;
	e1.final = 2;
	e2.comienzo =3;
	e2.final = 4;
	
	e3.comienzo =5;
	e3.final = 6;
	e4.comienzo =7;
	e4.final = 8;
	e5.comienzo =9;
	e5.final = 10;
	
	e6.comienzo =13;
	e6.final = 14;
	e7.comienzo =15;
	e7.final = 16;
	e8.comienzo =17;
	e8.final = 18;
	e9.comienzo =19;
	e9.final = 20;
	e10.comienzo =21;
	e10.final = 22;


	
	tLista *l = crearLista();
	

	append(l,e1);
	append(l,e2);
	append(l,e3);
	append(l,e4);
	append(l,e5);
	append(l,e6);
	append(l,e7);
	append(l,e8);
	append(l,e9);
	append(l,e10);
	Print(l);
/*
	Printelemento(getValue(l));
	next(l);
	next(l);
	next(l);
	next(l);
	next(l);
	Printelemento(getValue(l));
	prev(l);
	Printelemento(getValue(l));
	moveToStart(l);
	Printelemento(getValue(l));
	movetoEnd(l);
	Printelemento(getValue(l));

*/
	//next(l);

	//printf("El valor es: %d\n",lenght(l));
	//printf("El valor es: %d\n",currPos(l));
	
	//Printelemento(getValue(l));
	
	juntartodas(l);
	Print(l);
	
	
	return 0;
}


