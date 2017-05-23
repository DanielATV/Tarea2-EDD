#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "listaen.c"
#include "listaen.h"

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
void check(tLista *l)
{
	moveToStart(l);
	while(currPos(l) < length(l)-1)
	{
		if(juntar(l)!=0)next(l);
	}

}
int Free(tLista *lista1,tLista *lista2, int byte){
  int n,m,u;
  elemento a,b;
  for(moveToStart(lista2);currPos(lista2)<length(lista2); next(lista2)){
    a = getValue(lista2);
    n = a.comienzo;
    if (n == byte){
      m = a.final;
      for(moveToStart(lista1);currPos(lista1)<length(lista1); next(lista1)){
        b = getValue(lista1);
        u = b.comienzo;
        if (m < u){
          insert(lista1, a);
          lremove(lista2);
          return 0;
        }
      }
      append(lista1, a); //quizas es b
      lremove(lista2);
      return 0;
    }
  }
  
  return -1;
}

int Malloc(tLista *lista1,tLista *lista2, int byte)
{
	int k,n,m;
	elemento a,b;
	for(moveToStart(lista1);currPos(lista1) < length(lista1); next(lista1))
	{
		a = getValue(lista1);
		n = a.comienzo;
		m = a.final;
		k = m - n + 1;
		if (byte == k)
		{
			append(lista2,a);
			lremove(lista1);
			return 0;
		}
		else if ( byte < k)
		{
			b.final = a.final;
			a.final = a.comienzo + byte - 1;
			b.comienzo = a.comienzo + byte;
			append(lista2, a);
			lremove(lista1);
			insert(lista1, b);
			return 0;
		}
	}
	printf("aaaaa");
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

	
	

	//----Datos que manejan input.dat
	FILE *fp;
	fp = fopen("input.dat","r");
	int m;
	int n;
	fread(&m,sizeof(int),1,fp);
	fread(&n,sizeof(int),1,fp);
	//int nummallocs[n];
	//int numfrees[n];
	
	
	int contador =0;
	int numero=0;
	int estaenmalloc = 1;
	int estaenfree = 1;

	int espacio=1;
	int cants=0;


	char a = 'a';
	//---------------------------------

	tLista *L1 = crearLista();
	elemento e0;
	e0.comienzo = 1;
	e0.final = 100;
	append(L1,e0);
	tLista *L2 = crearLista();

	FILE *fp2;
	fp2 = fopen("output.dat","w");
	while(a!=EOF)
	{
		
		
		a = getc(fp);
		
		if(a=='m')	
		{
			estaenmalloc = 0 ;
			cants++;	
			//numfrees[cants-1]=0;
		}		
		else if(a=='f')
		{
			estaenfree = 0 ;
			
			cants++;
			//nummallocs[cants-1]=0;
		}		
					
			
		
		if(a=='\0')
		{
			//----------
			//se tiene la variable estaenmalloc/estaenfree que seran 0 si son V. Ademas del numero actual.
			
			//----------------------------------------ESTO ESTOY CAMBIANDO...
			if (estaenmalloc == 0)
			{	
				int funciono_malloc =Malloc(L1,L2,numero); //-1 no funciona, 0 funciona
				char b0[11]="Bloque de \0";
				char b1[35]=" bytes asignado a partir del byte \0";
				char b2[29]=" bytes NO puede ser asignado\0"; 
				char b[]="";
				char str1[50];
				sprintf(str1, "%d", numero);
				int numero2 = 999; //>>>>>>>>>>>>>>>>>>>>>>>>>REEMPLAZAR POR EL BYTE FINAL
				char str2[50];
				sprintf(str2, "%d", numero2);

				

				if (funciono_malloc == 0)
				{
					strcat(b,b0);
					strcat(str1,"\0");
					strcat(b,str1);
					strcat(b,b1);
					strcat(str2,"\0");
					strcat(b,str2);
					printf("lista1:\n");
					Print(L1);
					printf("lista2:\n");
					Print(L2);
					printf("%s\n",b);
					//fwrite(b,sizeof(b),1,fp2);
				}
				else	
				{
					printf("asd");
					strcat(b,b0);
					strcat(str1,"\0");
					strcat(b,str1);
					strcat(b,b2);
					printf("%s\n",b);
					//fwrite(b,sizeof(b),1,fp2);

				}
				estaenmalloc =1;
			}
			else if(estaenfree == 0)
			{
				Free(L1,L2,numero); //-1 no funciona, 0 funciona
				char b0[11]="Bloque de \0";
				char b1[16]=" bytes liberado\0";
				
				char b[]="";
				char str1[50];
				sprintf(str1, "%d", numero);
								
				strcat(b,b0);
				strcat(str1,"\0");
				strcat(b,str1);
				strcat(b,b1);
				printf("%s\n",b);
				//fwrite(b,sizeof(b),1,fp2);


			}
//----------------------------------------ESTO ESTOY CAMBIANDO...(ARRIBA)
			
			//se resetean.
			contador =0;
			estaenmalloc = 1;
			estaenfree =1;
			numero = 0;
			espacio = 1;
		}		
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
		if ( a==' ')	espacio=0;


		//if (estaenmalloc==0)	nummallocs[cants-1]=(int) numero;
		//else if (estaenfree==0)	numfrees[cants-1]=(int) numero;
		
	}
	fclose(fp);
	fclose(fp2);
	printf("%d\n%d\n",m,n);
	/*
	for (int i=0;i<n;i++)
	{
		printf("mallocs: %d\n",nummallocs[i]);
	}
	for (int i=0;i<n;i++)
	{
		printf("free: %d\n",numfrees[i]);
	}
	*/
	
	return 0;
	
}
