#include <stdio.h>
#include <string.h>

typedef struct Palabra{
    char palabra[20];
    int veces;
}Palabra;


void busca(Palabra palabras[],int *tamanioPtr,char *palabraPtr){
    for(int i=0;i<*tamanioPtr;i++){
        if(strcmp(palabras[i].palabra,palabraPtr)==0){
            palabras[i].veces++;
            return; 
        }
    }
    strcpy(palabras[*tamanioPtr].palabra,palabraPtr);
    palabras[*tamanioPtr].veces = 1;
    *tamanioPtr++;
}

void escribir(Palabra palabras[],int tamanioPtr){
    for(int i=0;i<tamanioPtr;i++){
        printf("%s %d\n",palabras[i].palabra,palabras[i].veces);
    }
}

int main(){
    
    Palabra palabras[100];
    char palabra[20];
    int tamanio = 0;
    while(scanf("%s",palabra)!=EOF){
        busca(palabras,&tamanio,palabra);
    }
    escribir(palabras,tamanio);
    return 0;
}
