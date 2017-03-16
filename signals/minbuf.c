#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void control_c(int signum){
    printf("Se atrapo la señal de SIGINT %d\n",signum);
    exit(signum);
}

int main(){
    signal(SIGINT,control_c);
    while(1){
        printf("Procesando\n");
        sleep(5);
    }
    return EXIT_SUCCESS;
}


