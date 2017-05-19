#include <stdio.h>
#include "lista_en.h"

void free(tLista *lista1,tLista *lista2, int byte){
  int n,m,u,v;
  elemento a;
  for(moveToStart(lista2);currentPos(lista2)<lenght(lista2); next(lista2)){
    a = getValue(lista2);
    n = a.comienzo;
    if (n == byte){
      m = a.final;
      remove(lista2);
      for(moveToStart(lista1);u = currentPos(lista1)<v; next(lista1)){
      
      
    }
  }
}
int Malloc(tLista *lista1,tLista *lista2, int byte){
  int i,j,k,n,m;
  elemento a,b;
  j = length(lista1);
  for(moveToStart(lista1);i = currPos(lista1)<j; next(lista1)){
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
      a.final = a.comienzo + k - 1;
      b.comienzo = a.comienzo + k;
      append(lista2, a);
      lremove(lista1);
      insert(lista1, b);
      return 0;
    }
  }
  return -1;
}
void check(tLista *lista1){}
int main(){
  return 0;
}
