#include <stdio.h>
#include <stdlib.h>

int main(){

    char nombre1[50],jugada1[2],nombre2[50],jugada2[2];

    while(1){
    	scanf("%s %s %s %s",nombre1,jugada1,nombre2,jugada2);
    	char *strings[] = {nombre1,jugada1};
    	/*strings[0] = nombre1;
    	strings[1] = jugada1;*/
    	printf("%s\n", strings[1]);
    }

    
}
