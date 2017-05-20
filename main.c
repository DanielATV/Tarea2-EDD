elemento lremove(tLista *l){
	tNodo *aux = l->curr->sig;
	elemento item = l->curr->sig->info;

	free((void *)aux);
	if (l->curr->sig->sig == NULL){ 
		l->tail = l->curr;
	}
	else{	
		l->curr->sig = l->curr->sig->sig;
	}
	free((void *)aux);
	l->pos --;
	l->listSize--;
	return item;	
}
