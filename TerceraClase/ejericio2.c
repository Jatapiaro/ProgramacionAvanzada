#include <stdio.h>

int main(){
    char *b = "Hola";
    printf("%lu %lu\n",(unsigned long)b,(unsigned long)(b+1));
}
