#include <stdio.h>
#include "cuadrado.h"

int main(){
    
    int n;

    printf("Dame un número: ");
    //& da la dirección de memoria de una variable
    scanf("%d",&n);

    printf("%d\n",cuadrado(n));

}
