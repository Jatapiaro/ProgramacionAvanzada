#include <stdio.h>
#include <stdlib.h>

int whoWins(char jugada,char jugada2){
	switch(jugada){
		case 'R':
			if(jugada2 == 'P'){
				return 2;
			}else{
				return 1;
			}
		case 'P':
			if(jugada2 == 'S'){
				return 2;
			}else{
				return 1;
			}
		case 'S':
			if(jugada2 == 'R'){
				return 2;
			}else{
				return 1;
			}
		default: 
			return -1;
	}
}

char ** ganador(char *(*jugador1),char *(*jugador2)){

	/*
	* Sacamos el char de la jugada que hizo
	*/
	char *j1 = jugador1[1];
	char *j2 = jugador2[1];

	/*
	* Como esta dado por un string como 5\0 debemos 
	* solo tomar el primer elemento
	*/
	if(j1[0] == j2[0]){
		return jugador1;
	}else{
		int who = whoWins(j1[0],j2[0]);
		if(who == 1){
			printf("%s %s\n", jugador1[0],jugador1[1]);
			return jugador1;
		}else{
			return jugador2;
		}
	}
}

int main(){

    char nombre1[50],jugada1[2],nombre2[50],jugada2[2];

    while(1){
    	scanf("%s %s %s %s",nombre1,jugada1,nombre2,jugada2);
    	char *jugador1[] = {nombre1,jugada1};
    	char *jugador2[] = {nombre2,jugada2};
    	char **gan = ganador(jugador1,jugador2);
    	printf("Gano: %s - %s\n", gan[0],gan[1]);
    }

    
}
