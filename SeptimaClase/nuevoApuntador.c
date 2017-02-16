#include <stdio.h>

int main(){
    
    /*
     * A esta en una dirección de memoria
     * que quien sabe donde esta
     * */
    int a = 10;

    /*
     * Declarando
     * */
    int *aPtr = &a;
    /*
     * Obtenemos la direcicón de memoria de a con &
     */

    printf("a = %d y  b = %llu\n",a,aPtr);
    
    int newA[] = {1,2,3};
    int newB[] = {4,5,6};

    int *newPtr = newA;
    int otro = *(newPtr+=3); 
}
