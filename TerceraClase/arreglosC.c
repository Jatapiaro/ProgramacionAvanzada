#include <stdio.h>


void modifica(int *arr, int ncolumnas,int renglon,int columna,int nuevoValor){
    int casilla;
    casilla = renglon * ncolumnas + columna;
    *(arr + casilla) = nuevoValor;
    //printf("Direccion donde va: %d\n",casilla);
    arr[casilla] = nuevoValor;
}

void modifica2(int arr[][3],int  nuevoValor, int renglon,int columna){
    arr[renglon][columna] = nuevoValor;
}

int main(){
    
    int arr[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    modifica((int *)arr,4,1,2,100);
    printf("Nevo valor %d\n",arr[1][2]);
    modifica2((int (*)[3])arr,200,2,0);
    printf("Nuevo valor %d\n", arr[1][2]);
}
