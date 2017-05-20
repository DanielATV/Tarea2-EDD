#include <stdio.h>
#include "lista_en.h"

void Free(tLista *lista1,tLista *lista2, int byte){
  int n,m,u;
  elemento a,b;
  for(moveToStart(lista2);currentPos(lista2)<lenght(lista2); next(lista2)){
    a = getValue(lista2);
    n = a.comienzo;
    if (n == byte){
      m = a.final;
      for(moveToStart(lista1);currentPos(lista1)<lenght(lista1); next(lista1)){
        b = getValue(lista1);
        u = a.comienzo;
        if (m < u){
          insert(lista1, b);
          remove(lista2);
          return 0;
        }
      }
      append(lista1, b);
      remove(lista2);
      return 0;
    }
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
