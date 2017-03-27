#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <unistd.h>
#define THREADS 4

void* th(void *arg) {
	int id = *((int *) arg); 
	printf("Hola mundo %d\n", id);
	pthread_exit(0); 
}

int main(int argc, const char * argv[]) {
	pthread_t threads[THREADS];
	pthread_attr_t attr;

	/* inicializa los atributos para los threads */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_JOINABLE ); 
	pthread_attr_setscope( &attr, PTHREAD_SCOPE_SYSTEM );

	int i;
	for (i = 0;i <THREADS;i++) {
		int tmp = pthread_create(&threads[i], &attr, th, (void *) &i); 
		sleep(1);
		if (tmp != 0) {
			printf("Problemas al crear el thread %d\n", i);
			exit(EXIT_FAILURE); 
		}
	}
	int j;
	/* esperando la terminación de los threads hijos */ 
	for (j = 0;j <THREADS;j++) {
		int tmp = pthread_join(threads[j], NULL); 

		if (tmp != 0) {
			printf("Problemas esperando al thread %d\n", j);
			exit(EXIT_FAILURE); 
		}
	}
	return 0; 
}
