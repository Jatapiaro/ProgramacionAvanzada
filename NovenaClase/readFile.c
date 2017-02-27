#include <stdio.h>
#include <stdlib.h>
int main(){
    char archivo[] = "archivo.txt";
    FILE *fptr = fopen(archivo,"w");
    if(fptr==NULL){
        fprintf(stderr,"Problemas al abrir el archivo\n");
    }
    fprintf(fptr,"Hola mundo sobre archivo\n");
    fprintf(fptr,"Otra linea\n");
    fprintf(stderr,"Esto va  a la salida de error\n");
    fprintf(stdout, "Esto va a la salida estandar\n");
    exit(1);
    flcose(fptr);
    return 0;
}
