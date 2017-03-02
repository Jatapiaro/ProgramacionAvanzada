#include <unistd.h>
#include <stdio.h>

int main(){
    const char *c1,*c2;
    c1 = "Hola";
    pid_t pid;
    if((pid = fork())){
        c2 = "Mundo ";
        sleep(10);
    }else{
        c1 = "Adios ";
        c2 = "Proceso hijo";
    }
    printf("%s %s pid = %d, pid = %d\n",c1,c2,pid,getpid());
}
