#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    int edad;
} persona;

typedef struct nodo{
    persona per;
    struct nodo *siguiente;
} nodo;

void inserta(nodo *n,persona *per){
    if(n->siguiente == NULL){
        n->siguiente = malloc(sizeof(nodo));
        n->siguiente->per = per;
        n->siguiente->siguiente = NULL;
    }else{
        inserta(n->siguiente,per);
    }
}

persona *leePersona(){
    persona *per = malloc(sizeof(persona));
    printf("Dame un nombre:");
    scanf("%s\n",per->nombre);
    printf("Dame su edad:");
    scanf("%d\n",&(per->edad));
    return per;
}

void imprime(nodo *n){
    while(n!=NULL){
        printf("Nombre: %s, Edad: %d\n",n->per.nombre,n->per.edad);
        n = n->siguiente;
    }
}



int main(){
    nodo raiz;
    persona *per = leePersona();
    inserta(raiz,per)
    imprime(&raiz);
}

