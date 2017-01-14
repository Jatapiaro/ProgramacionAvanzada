#include <stdio.h>

int main(int argc,char **argv){
    
    char *pointer;
    
    printf("%d\n",argc);
    
    for(int i=0;i<argc;i++){
        printf("%ld - ",(int)argv);
        printf("%s\n",*argv++);
    }

    long int ptr = (long int)(argv+1);
    printf("%ld\n",(char*)ptr);

}
