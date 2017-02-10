#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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
			///printf("%s %s\n", jugador1[0],jugador1[1]);
			return jugador1;
		}else{
			return jugador2;
		}
	}
}


char ** jugarTorneo(char *jugadores[][2][2][2],int njugadores){

	char **arr = (char **)jugadores;
	int marcador[njugadores];
	int nPares = njugadores/4;
	int contador = 0;
	int tirada = 2;

	for(int w=0;w<njugadores;w++){
		if(marcador[w]==0){
			contador++;
		}
	}
	
	do{	
		char **jugador1, **jugador2;
		for(int i=0;i<njugadores;i){
			int posi,posk;
			posi = 0;
			posk = 0;
			if(marcador[i]==0){
				int pp = i*2;
				char *jug[] = {*(arr+pp),*(arr+(pp+1))};
				jugador1 = jug;
				posi = i;
			}

			for(int k=i+1;k<njugadores-1;k++){
				if(marcador[k]==0){
					int pp = k*2;
					char *jug[] = {*(arr+pp),*(arr+(pp+1))};
					jugador2 = jug;
					posk = k;
					break;
				}
			}
			char **winner = ganador(jugador1,jugador2);
			//printf("%s - %s \n", winner[0] , winner[1]);
			if(strcmp(winner[0], jugador1[0]) == 0){
				/*
				* Verificamos quien gano y marcamos al perdedor en el marcador
				* Se usa true para marcar que perdio para no hacer un recorrido
				* inicial donde se marquen todos como true.
				*/
				marcador[posk] = 1;
			}else{
				marcador[posi] = 1;
			}

			if(tirada==2){
				i+=2;
			}else{
				i++;
			}
		}
		if(tirada==2){
			tirada=1;
		}

		contador = 0;
		for(int w=0;w<njugadores;w++){
			if(marcador[w]==0){
				contador++;
			}
		}

	}while(contador>4);


	

	/*for(int i=0;i<njugadores;i++){
		printf("%d\n", marcador[i]);
	}*/

	char **jugador3, **jugador4,**jugador5, **jugador6;
	int posi = 0;
	for(int i=0;i<njugadores;i++){
		if(marcador[i]==0){
			int pp = i*2;
			char *jug[] = {*(arr+pp),*(arr+(pp+1))};
			jugador3 = jug;
			posi = i;
			break;
		}
	}
	for(int i=posi+1;i<njugadores;i++){
		if(marcador[i]==0){
			int pp = i*2;
			char *jug[] = {*(arr+pp),*(arr+(pp+1))};
			jugador4 = jug;
			posi = i;
			break;
		}
	}

	for(int i=0;i<njugadores;i++){
		if(marcador[i]==0){
			int pp = i*2;
			char *jug[] = {*(arr+pp),*(arr+(pp+1))};
			jugador5 = jug;
			posi = i;
			break;
		}
	}
	for(int i=posi+1;i<njugadores;i++){
		if(marcador[i]==0){
			int pp = i*2;
			char *jug[] = {*(arr+pp),*(arr+(pp+1))};
			jugador6 = jug;
			posi = i;
			break;
		}
	}

	char **finalista1, **finalista2;


	finalista1 = ganador(jugador3,jugador4);
	finalista2 = ganador(jugador5,jugador6);

	return ganador(finalista1,finalista2); 
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
            	{"Dave","S"}
            },
            {
            	{"Richard", "R"}, 
            	{"Michael", "S"}
            }
        },

        {
            {
            	{"Allen", "S"},
            	{"Omer", "P"}
            },
            {
            	{"Carlos", "R"},
            	{"Juan.", "P"}
            }
        }
    };

    char **gan = jugarTorneo(juego2,8);

    printf("El ganador del juego es: %s - %s\n", gan[0],gan[1]);
    
}
