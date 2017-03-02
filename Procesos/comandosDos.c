#include <stdio.h>
#include <unistd.h>
int main(){
    char *argv[2] = {"./hola",NULL};
    execvp("./hola",argv);
    printf("adios");
}
