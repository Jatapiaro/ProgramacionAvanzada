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

void jugarTorneo(char *jugadores[][2][2][2],int njugadores){

	char **jugadoresL[njugadores];
	char **arr = (char **)jugadores;

	int pos = 0;
	for(int i=0;i<njugadores;i++){
		char *jug[] = {*(arr+pos),*(arr+(pos+1))};
		printf("%s - %s\n",jug[0],jug[1]);
		jugadoresL[i] = jug;
		pos+=2;
	}

	for(int i=0;i<njugadores;i++){
		printf("%s - %s\n",**njugadores[0],**njugadores[1]);
	}

}

int main(int argc, char **argv){

	/*Descomentar para probar la primera parte*/

    /*char nombre1[50],jugada1[2],nombre2[50],jugada2[2];

    while(1){
    	scanf("%s %s %s %s",nombre1,jugada1,nombre2,jugada2);
    	char *jugador1[] = {nombre1,jugada1};
    	char *jugador2[] = {nombre2,jugada2};
    	char **gan = ganador(jugador1,jugador2);
    	printf("Gano: %s - %s\n", gan[0],gan[1]);
    }*/

	/*
	* Cada 2 elementos hay dos elementos que a su vez tienen dos elementos
	* Un [] del array tiene dos arrays, cada array con dos arrays de chars
	*/
    char *juego2[][2][2][2] = {
        {
            {
            	{"Armando","P"},
            	{"Dave","T"}
            },
            {
            	{"Richard", "R"}, 
            	{"Michael", "T"}
            }
        },

        {
            {
            	{"Allen", "T"},
            	{"Omer", "P"}
            },
            {
            	{"David E.", "R"},
            	{"Richard X.", "P"}
            }
        }
    };

    jugarTorneo(juego2,8);

    
    /*printf("%s\n", juego2[0][0][0][0]);
    char **arr = (char **)juego2;
    printf("%s\n", *(arr+3));*/
    
}
