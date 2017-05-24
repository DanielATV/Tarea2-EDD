#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.c" //depende de como lo tengas tu

void creardat(){
	FILE *fp;
	fp = fopen("input.dat","w");
	fprintf(fp, "%d\n",100 );
	fprintf(fp, "%d\n",9 );

	fprintf(fp, "%s %d\n","malloc",10);
	fprintf(fp, "%s %d\n","malloc",20);
	fprintf(fp, "%s %d\n","malloc",10);
	fprintf(fp, "%s %d\n","malloc",40);
	fprintf(fp, "%s %d\n","malloc",21);
	fprintf(fp, "%s %d\n","free",31);
	fprintf(fp, "%s %d\n","malloc",5);
	fprintf(fp, "%s %d\n","malloc",10);
	fprintf(fp, "%s %d\n","malloc",5);
	fclose(fp);

}




int main(){
	//creardat();
	FILE *fp;
	char operacion[10];
	int m,n,valor;
	fp = fopen("input.dat","r");
	fscanf(fp,"%d\n%d\n",&m,&n); //nose si esta bien

	fscanf(fp,"%s %d\n",&operacion,&valor ); //dentro de un ciclo para n lineas


	return 0;
	
}
