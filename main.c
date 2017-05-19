#include <stdio.h>
#include "lista_en.h"

void free(tLista *lista1,tLista *lista2, int byte){
  int i,j,n,m;
  elemento a;
  j = lenght(lista2);
  for(moveToStart(lista2);i = currentPos(lista2)<j; next(lista2)){
    a = getValue(lista2);
    n = a.comienzo;
    if (n == byte){
      
    }
  }
}
int malloc(tLista *lista1,tLista *lista2, int byte){
  int i,j,k,n,m;
  elemento a,b;
  j = lenght(lista1);
  for(moveToStart(lista1);i = currentPos(lista1)<j; next(lista1)){
    a = getValue(lista1);
    n = a.comienzo;
    m = a.final;
    k = m - n + 1;
    if (byte == k){
      append(lista2,a);
      remove(lista1);
      return 0;
    }
    else if ( byte < k){
      b.final = a.final;
      a.final = a.comienzo + k - 1;
      b.inicial = a.comienzo + k;
      append(lista2, a);
      remove(lista1);
      insert(llista1, b);
    }
  }
  return -1;
}
void check(tLista *lista1){}
int main(){
  return 0;
}
