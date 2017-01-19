#include <stdio.h>

void imprime(char c,int veces){
    int i;
    for(i=0;i<veces;i++){
        printf("%c",c);
    }
}

int main(){

    int pisos,blancos,asteriscos;
    printf("Dame el número de pisos de tu rombo:\n");
    scanf("%d",&pisos);

    blancos = pisos/2;
    asteriscos = 1;

    int i;

    for(i=0;i<pisos/2;i++){
        imprime(' ',blancos);
        imprime('*', asteriscos);
        blancos-=1;
        asteriscos +=2;
        printf("\n");
    }

    imprime('*',pisos);
    printf("\n");

    for(i=pisos/2;i>=0;i--){
        imprime(' ',blancos);
        imprime('*',asteriscos);
        blancos+=1;
        asteriscos-=2;
        printf("\n");
    }
}
