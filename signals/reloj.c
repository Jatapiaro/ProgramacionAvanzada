#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void alarma(){
    printf("El temporizador expiro\n");
    exit(EXIT_FAILURE);
}

int main(){

    char nombre[40];

    signal(SIGALRM,alarma);
    
    printf("Tienes 5 segundos para decirme tu nombre: ");
    fflush(stdout);

    alarm(3);

    //gets(nombre);
    scanf("%s",nombre);
    alarm(0);

    printf("Tu nombre es: %s\n",nombre);
}
