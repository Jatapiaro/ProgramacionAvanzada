#include <stdlib.h> 
#include <stdio.h> 

#define MAXLEN 100 
char * mifgets(char*,int,FILE*);
int main() { 
	char tline[MAXLEN]; /* Una "línea" de texto */ 
        FILE *fptr = fopen("archivo.txt","r"); 
	if(fptr != NULL) {  
		while(mifgets(tline, MAXLEN, fptr) != NULL) { 
			printf("%s",tline);  
	    } 
	    fclose(fptr); 
	}else{
		fprintf(stderr,"Error al abrir el archivo\n"); 
	}
	return 0; 
} 
