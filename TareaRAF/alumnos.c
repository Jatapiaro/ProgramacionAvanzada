#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 78

typedef struct Estudiante {
  char matricula[10];
  char nombre[51];
  char correo[19];
  short siguiente;
} Estudiante;



void impresion(Estudiante e){
	printf("Matrícula: %s Nombre: %s Correo: %s Siguiente: %hd\n", e.matricula, e.nombre, e.correo, e.siguiente);
}


/*
* Regresa el elemento más pequeño actual
*/
int insercion(Estudiante estudiantes[1000],Estudiante e,int registros,int pequenio){
	
	FILE *fp;

	
	fp = fopen ("estudiantes2.txt", "w");

	if(registros == 0){
		e.siguiente = -1;
		estudiantes[0] = e;	
		return 0;
	}

	int i = pequenio;
	int padre = i;
	int booleano = 1;
	if(strcmp(e.nombre,estudiantes[i].nombre)<0){
		booleano = 0;
		e.siguiente = 0;
		estudiantes[registros] = e;
	}
	while(booleano){
		if(estudiantes[i].siguiente == -1){
			if(strcmp(estudiantes[i].nombre,e.nombre)<0){
				estudiantes[i].siguiente = registros;
				e.siguiente = -1;
				estudiantes[registros] = e;
				break;
			}else{
				int aux = estudiantes[padre].siguiente;
				e.siguiente = aux;
				estudiantes[padre].siguiente = registros;
				estudiantes[registros] = e;
				break;
			}
		}else{
			if(strcmp(e.nombre,estudiantes[i].nombre)<0){
				int aux = estudiantes[padre].siguiente;
				e.siguiente = aux;
				estudiantes[padre].siguiente = registros;
				estudiantes[registros] = e;
				break;
			}else{
				padre = i;
				i = estudiantes[i].siguiente;
			}
		}
	}

	int j = 0;
	char *minor = estudiantes[0].nombre;
	/*
	* Recorremos el arreglo para buscar el menor
	*/
	for(int i=0;i<=registros;i++){
		if(strcmp(estudiantes[i].nombre,minor)<0){
			j = i;
			minor = estudiantes[j].nombre;
		}
	}
	/*
	*Metemos en el file el menor
	*/
	fprintf(fp, "%d\n",j);
	/*
	*Movemos el tamaño del int mas uno (\n) el
	*apuntador, para empezar a escribir despúes
	*/
	long w = sizeof(int)+1;
	fseek(fp,w,SEEK_END);
	for(int i=0;i<=registros;i++){
		fseek(fp,i*sizeof(Estudiante),SEEK_END);
		fprintf(fp, "%s %s %s %hd\n", estudiantes[i].matricula,estudiantes[i].nombre,estudiantes[i].correo,estudiantes[i].siguiente);
	}
	fclose(fp);
	return j;

}

Estudiante stdinLec(){
	printf("Escribe matricula nombre correo separados por una espacio\n");
	Estudiante e;
	scanf("%s %s %s",e.matricula,e.nombre,e.correo);
	e.siguiente = 0;
	return e;
}

Estudiante lee(FILE* archivo, int reg){
	long pos = 77 *reg;
	Estudiante e;
	fseek(archivo, pos, SEEK_SET);
	fread(&(e.matricula), 9, 1, archivo);
	e.matricula[9] = '\0';
	fread(&(e.nombre), 50, 1, archivo);
	e.nombre[50] = '\0';
	fread(&(e.correo),18, 1, archivo);
	e.correo[18] = '\0';
	e.siguiente = 0;
	return e;
}

int main()
{
	Estudiante est[1000]; 

	FILE* alumno1 = fopen("estudiantes", "rb");
	
	fseek(alumno1, 0, SEEK_END);

	int regs = ftell(alumno1) / 77;

	printf("Numero de registros %d\n", regs );


	int menor = -1;
	int i;
	for(i=0; i<regs;i++){
		Estudiante es = lee(alumno1, i);
		menor = insercion(est,es,i,menor);
	}

	int option = -1;
	int valido = 1;
	while(valido){
		printf("Escoge una opción: \n\t1.Ingresar registro desde consola \n\t2.Borrado\n\t3.Impresion\n\t4.Salir\n");
		scanf("%d",&option);
		Estudiante es;
		switch(option){
			case 1:
				es = stdinLec();
				menor = insercion(est,es,i,menor);
				i++;
				break;
			case 4:
				break;
		}
	}

	return 0;
}