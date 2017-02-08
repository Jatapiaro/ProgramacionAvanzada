#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int rand1 = 12;
	int rand2 = 15;

	printf("rand1 = %p : rand2 = %p\n", &rand1,&rand2);
	printf("rand1 = %d : rand2 = %d\n", &rand1,&rand2);

	// the address is stored in *prand1
	int *pRand1 = &rand1;
	printf("rand1 = %p\n", pRand1);
	printf("rand1 = %d\n", pRand1);

	/*
	*Get value of pointer
	*/
	printf("Value: %d\n", *pRand1);
}
