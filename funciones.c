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

