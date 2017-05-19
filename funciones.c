void check(tLista *l){
	moveToStart(l);
	while(l->curr != l->tail)
	{
		int comienzo1 = getValue(l).final;
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
			//tNodo n0;
			//n0.info = e0;
			//n0.sig = l->curr->sig->sig;
			
			insert(l,e0);
			next(l);
			lremove(l);
			next(l);
			lremove(l);
			
			
			
		}

	}

}
