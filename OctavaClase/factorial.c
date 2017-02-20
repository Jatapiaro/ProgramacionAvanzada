//Compile with

//gcc -o factorial -O0 -g factorial.c

//or

//gcc -o factorial -O3 -g factorial.c 

#include <stdio.h>

int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int factorial2(int n,int res){
    if(n==0){
        return res;
    }
    return factorial2(n-1,res*n);
}

int main(){
    printf("%d\n",factorial(11));
}
