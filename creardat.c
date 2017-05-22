	#include <stdlib.h>
#include <stdio.h>
#include<string.h>
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

void juntartodas(tLista *l)
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
      modificarC(lista1,b.comienzo);
      modificarF(lista1,b.final);

      return 0;
    }
  }
  return -1;
}

void creardat(){
	FILE *fp;
	fp = fopen("input.dat","w");
	int m = 100;
	int n = 9;
	fwrite(&m,sizeof(int),1,fp);
	fwrite(&n,sizeof(int),1,fp);
	
	char str1[]="malloc 10";
	char str2[]="malloc 20";
	char str3[]="malloc 10";
	char str4[]="malloc 40";
	char str5[]="malloc 21";
	char str55[]="free 31";
	char str6[]="malloc 5";
	char str7[]="malloc 10";
	char str8[]="malloc 5";
	
	fwrite(str1,sizeof(str1),1,fp);
	fwrite(str2,sizeof(str2),1,fp);
	fwrite(str3,sizeof(str3),1,fp);
	fwrite(str4,sizeof(str4),1,fp);
	fwrite(str5,sizeof(str5),1,fp);
	fwrite(str55,sizeof(str55),1,fp);
	fwrite(str6,sizeof(str6),1,fp);
	fwrite(str7,sizeof(str7),1,fp);
	fwrite(str8,sizeof(str8),1,fp);
	fclose(fp);

}




int main(){
	//creardat();

	
	

	//probar sscanf
	//ir leyendo y escribiendo altiro . 
	FILE *fp;
	fp = fopen("input.dat","r");
	int m;
	int n;
	fread(&m,sizeof(int),1,fp);
	fread(&n,sizeof(int),1,fp);
	
/*
	char line[100];
	fread(line,sizeof(line),1,fp);
	fprintf(line," )

	
	
	fclose(fp);
	*/
	
	int nummallocs[n];
	int numfrees[n];
	
	
	
	char a = 'a';
	
	int cantmallocs = 0;
	int cantfrees = 0;
	int contador =0;
	int numero=0;
	int estaenmalloc = 1;
	int estaenfree = 1;

	int espacio=1;
	int cants=0;

	
	while(a!=EOF)
	{
		
		
		a = getc(fp);
		
		if(a=='m')	
		{
			estaenmalloc = 0 ;
			cantmallocs++;
			cants++;	
			numfrees[cants-1]=0;
		}		
		else if(a=='f')
		{
			estaenfree = 0 ;
			cantfrees++;
			cants++;
			nummallocs[cants-1]=0;
		}		
					
			
		
		if(a=='\0')
		{
			//----------> aqui ejecutar main
			contador =0;
			estaenmalloc = 1;
			estaenfree =1;
			numero = 0;
			espacio = 1;
		}		
		
		if (estaenmalloc==0)
		{
			if (espacio==0)
			{
				contador++;
				if (contador==1)	numero = a-'0';
				else
				{	
					numero = numero*10;
					numero+= a-'0';
				}
				contador++;
			}
			nummallocs[cants-1]=(int) numero;
			if ( a==' ')	espacio=0;
			

		}
		else if (estaenfree==0)
		{
			
			if (espacio==0)
			{
				contador++;
				if (contador==1)	numero = a-'0';
				else
				{	
					numero = numero*10;
					numero+= a-'0';
				}
				
				contador++;
			}
			numfrees[cants-1]=(int) numero;
			if ( a==' ')	espacio=0;
		}	
	}
	fclose(fp);

	printf("%d\n%d\n",m,n);
	for (int i=0;i<n;i++)
	{
		printf("mallocs: %d\n",nummallocs[i]);
	}
	for (int i=0;i<n;i++)
	{
		printf("free: %d\n",numfrees[i]);
	}
	
	return 0;
	
}
