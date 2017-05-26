#include <stdio.h>
#include "listaen.h"
#include <string.h>

/*****
*
int Free()
******
*
A partir de el inicio de un bloque de memoria (byte) se busca en la lista Lista2, despues se elimina
de dicha lista, se asigna a la lista de bloques libres (Lista1), conservando el orden de la lista, y se entrega el tamaño 
del segmento de memoria liberado.
******
*
Input:
*
tLista *lista1: Lista 1 donde cada nodo son los bloques libres de memoria.
tLista *lista2: Lista 2 donde cada nodo son los bloques ocupados de memoria.
int byte: inicio del bloque de memoria a liberar.
*
******
*
Returns:
*
int, el tamaño del bloque de memoria liberado.
*****/
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
          return m-n+1;
        }
      }
      append(lista1, a); //quizas es b
      lremove(lista2);
      return m-n+1;
    }
  }
  
  return -1;
}
/*****
*
int Malloc()
******
*
A partir del tamaño del bloque de memoria (byte), se busca un nodo en Lista1 el cual tenga el mismo tamaño
o superior, si lo encuentra se introduce en la lista2 solo la parte ocupada del nodo, acortandolo de la lista1 y si 
no encuentra un bloque de memoria que satisfaga el requerimiento retorna un valor -1.
******
*
Input:
*
tLista *lista1: Lista 1 donde cada nodo son los bloques libres de memoria.
tLista *lista2: Lista 2 donde cada nodo son los bloques ocupados de memoria.
int byte: es la cantidad de memoria que se busca asignar en Lista2.
*
******
*
Returns:
*
int, retorna el inicio del bloque de memoria asignado, si no se pudo asignar se retorna -1.
*****/
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
      return n;
    }
    else if ( byte < k){
      b.final = a.final;
      a.final = a.comienzo + byte - 1;
      b.comienzo = a.comienzo + byte;
      append(lista2, a);
      lremove(lista1);
      insert(lista1, b);

      return n;
    }
  }
  return -1;
}
/*****
*
int juntar()
******
*
Se toma el nodo actual [i,j], se compara con el siguiente [m,n], y si el termino del bloque de memoria (j)
es continuo con el inicio del siguiente nodo (m), se eliminan ambos nodos y se reemplazan con un unico 
nodo el cual va del inicio del primero hasta el final del segundo [i,n].
******
*
Input:
*
tLista *lista1: Lista 1 donde cada nodo son los bloques libres de memoria.
*
******
*
Returns:
*
int, retorna 0 si se produjo la union entre dos nodos y retorna 1 en el caso de que los nodos no fueran continuos.
*****/
int juntar(tLista *l){
  int comienzo1,comienzo2,final1,final2;
  elemento aux;

  comienzo1 = getValue(l).comienzo;
	final1 = getValue(l).final;
	next(l);

  if (currPos(l) < length(l)-1) return -1;

	comienzo2 = getValue(l).comienzo;
	final2 = getValue(l).final;
	prev(l);

	if (final1 == comienzo2-1){

		aux.comienzo = comienzo1;
		aux.final = final2;

		lremove(l);
    lremove(l);
    insert(l,aux);
	
		return 0;
	}
	return -1;
/*****
*
int Check()
******
*
Primero se va al inicio de la lista, luego se ejecuta la funcion juntar() en donde si el bloque de memoria no
es contiguo al siguiente, se avanza al siguiente nodo y se realiza lo mismo hasta terminar. En el caso de que los bloques 
fueran contiguos se unen pere no se avanza al siguiente, de esta forma vemos si el nuevo bloque es contiguo al siguiente 
repitiendo el proceso mencionado anteriormente.
******
*
Input:
*
tLista *lista1: Lista 1 donde cada nodo son los bloques libres de memoria.
*
******
*
Returns:
*
void, no necesitamos que retorne nada.
*****/
}

void check(tLista *l)
{
  moveToStart(l);
	while(currPos(l) < length(l)-1){
		if(juntar(l)!= 0)next(l);
	}

}
/*****
*
int main()
******
*
Hace funcionar todo el programa, lee el archivo de texto mencionado y dependiendo de la instruccion llama a Malloc() o a 
Free(), en el ultimo caso despues emplea la funcion Check() para unir los bloques de memoria contiguos en Lista1, y 
finalmente dependiendo de lo que retornen las funciones se escribe en un nuevo archivo de texto 'output.dat' si se pudo
realizar bien las instrucciones entregadas.
******
*
Input:
*
void.
*
******
*
Returns:
*
int, retorna 0 por convencion.
*****/
int main(void){
  FILE *fp;
  tLista *lista1,*lista2;
  elemento item;
  int i,n,m,a,b,byte;
  char accion[10];
  char free[]="free";

  lista1 = crearLista();
  lista2 = crearLista();
  item.comienzo = 1;

  fp = fopen("input.dat","r");

  fscanf(fp, "%d", &n);
  item.final = n;
  append(lista1,item);
  fscanf(fp, "%d", &m);

  FILE *fp2;
  fp2 =fopen("output.dat","w");

  for (i=0;i<m;i++){
    fscanf(fp, "%s %d", accion, &byte);
    
    
    if(strcmp(free,accion)== 0){
    	b = Free(lista1,lista2, byte);
    	check(lista1);
      fprintf(fp2, "Bloque de %d bytes liberado\n",b);
    }
    else {
      a = Malloc(lista1,lista2,byte);
      if (a!=-1) fprintf(fp2, "Bloque de %d bytes asignado a partir del byte %d\n",byte,a);
      else  fprintf(fp2, "Bloque de %d bytes NO puede ser asignado\n",byte);
    }

  }

  fclose(fp);
  fclose(fp2);
  clearL(lista1);
  clearL(lista2);
  return 0;
}

