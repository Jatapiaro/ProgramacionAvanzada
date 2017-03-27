#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int cuenta = 0;

void control_c(int signum){
    /*
     *Variable con memoria
     *no se inicializa cada vez
     */
   //static int cuenta = 0;
    if(cuenta == 0 ){
        printf("Se atrapo la señal de SIGINT %d\n",signum);
        printf("Digita nuevamente control c para terminar\n");
        alarm(5);
        cuenta++;
    }else{
        exit(signum);
    }
}

void alarma(int signum){
    printf("El temporizador expiro\n");
    cuenta = 0;
}

int main(){
    signal(SIGINT,control_c);
    signal(SIGALRM,alarma);
    //alarm(5);
    while(1){
        printf("Procesando\n");
        sleep(5);
    }
    return EXIT_SUCCESS;
}


