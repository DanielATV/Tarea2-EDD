void check(tLista *l)
{
	printf("entro check\n");
	
	int abc = -1;
	
	
	while(abc !=0)
	{
		printf("---a---\n");
		abc=0;
		moveToStart(l);
		
		while(currPos(l) < length(l)-1)
		{
			printf("---b---\n");
			abc += juntar(l);
			next(l);
		}

		
	}
	

	/*

	moveToStart(l);
	while(currPos(l) < length(l)-1)
	{
		if(juntar(l)!=0)next(l);
	}



	*/
	

}
