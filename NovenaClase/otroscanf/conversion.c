#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b;
    /*
     * Se va a leer de un string
     */
    char *ptrC = "12 34"; 
    sscanf(ptrC,"%d %d",&a,&b);
    printf("a = %d b = %d\n",a,b);
}
