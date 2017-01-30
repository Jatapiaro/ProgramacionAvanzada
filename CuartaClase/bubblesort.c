#include <stdio.h>

//Apuntador a funcion que recibe dos int,int
int algo(int (*oper)(int,int),int a,int b){
    return oper(a,b);   
}

int suma(int a,int b){
    return a+b;
}

int resta(int a,int b){
    return a-b;
}

int compara(int a,int b){
    if(a < b){
        return -1;
    }else if(a == b){
        return 0;
    }else{
        return 1;
    }
}

void burbuja(int *arr,int tamanio,int(*comp)(int,int)){
    int intercambio = 1;
    int x = tamanio;
    while(intercambio){
        intercambio = 0;
        for(int i = 0; i < x-1 ; i++){
            for(int j=i+1;j<x;j++){
                if(comp(arr[i],arr[j]) == 1){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    intercambio = 1;
                }
            }
        }
        x--;
    }
}

int main(){
    int a[] = {12,34,21,100,10};
    burbuja(a,5,&compara);
    for(int i = 0;i<5;i++){
        printf("%d,",a[i]);
    }
    printf("\n");
    printf("%d\n",algo(&suma,7,5));
    printf("%d\n",algo(&resta,7,5));
}
