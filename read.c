#include <stdio.h>
#include <string.h>



int main(void){
   FILE *fp;
   int i,n,m, byte;
   char accion[10];
   char free[]="free";

   fp = fopen("results.dat","r");
   fscanf(fp, "%d", &n);
   fscanf(fp, "%d", &m);

   for (i=0;i<m;i++){
      fscanf(fp, "%s %d", accion, &byte);
      
      if(strcmp(free,accion)== 0) printf("Queso\n" );
      else printf("Jamon\n");
      printf("byte: %d,  accion %s\n", byte, accion);
   }

   fclose(fp);

   return 0;
}
