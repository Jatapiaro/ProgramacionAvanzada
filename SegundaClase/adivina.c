#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  srand(time(NULL));
  
  int random,userGuess,intentos;
  
  random = rand()%100;
  printf("The random %d:\n",random);
  intentos = 1;
    
  printf("Dame un número: \n");
  scanf("%d",&userGuess);
  while(random!=userGuess){
    printf("Intenta nuevamente\n");
    scanf("%d",&userGuess);
    intentos++;
  }
  printf("Exito, el numero es %d con %d intentos!\n",userGuess,intentos);
}

