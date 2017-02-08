#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	int prime[] = {2,3,5,7};

	printf("First index: %d\n", prime[1]);
	printf("First index: %d\n", *(prime+1));

	return 0;
}