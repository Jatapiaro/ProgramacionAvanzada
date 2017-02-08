#include <stdio.h>
#include <stdlib.h>

typedef struct Autor{
	const char *p_nombre;
	struct Autor *siguiente;
}Autor;

typedef struct Libro{
	const char *p_titulo;
	const char *p_editorial;
	long isbn;
	struct Autor *p_autor;
}Libro;



void printLibro(Libro l){
	Autor *p_a = l.p_autor;
	printf("%s\n",p_a->p_nombre);
}

void addAutor(Libro *p_libro,Autor a){
	Autor *p_aux = p_libro->p_autor;
	if(p_aux == NULL){
		p_aux->p_nombre = a.p_nombre;
		p_aux->siguiente = NULL;
	}
}

int main(){
	Autor a = {"JK",NULL};
	Libro l = {"Harry ","JSAD",28193,NULL};
	addAutor(&l,a);
	//printLibro(l);
}