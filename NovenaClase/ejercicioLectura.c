#include <stdio.h>
#include <stdlib.h>

char* mifgets(char *ptr, int tamanio, FILE *fptr){
    char *res = fgets(ptr,tamanio,fptr);
    if(res == NULL){
        return res;
    }
    int i=0;
    while(i<tamanio && ptr[i]!='\0' && ptr[i]!='\n'){
        i++;
    }
    if(i<tamanio){
        ptr[i] = '\0';
    }
    return res;
}


