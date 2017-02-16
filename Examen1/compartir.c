#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_entradas 500
typedef struct Entrada {
  char palabra[20];     /* la palabra */
  int lineas[10];   /* el número de línea en el que aparece */
  int total;        /* total de apariciones de la palabra en el texto */
}Entrada;

int split(char *str, char palabras[][21]) {
  int i = -1;
  char *tmp;
  tmp = strtok(str," \t\n.¿?:");
  while(tmp) {
    strcpy(palabras[++i],tmp);
    tmp = strtok(NULL," \t\n.¿?:");
  }  
  return ++i;
}

int agrega(Entrada entradas[max_entradas],char *pal,int elementosActuales,int linea){
  for(int i=0;i<max_entradas;i++){
    if(strcmp(pal, entradas[i].palabra) == 0 && linea!=entradas[i].total){
      entradas[i].total++;
      int x = entradas[i].total;
      entradas[elementosActuales].lineas[x-1] = linea;
      strcpy(entradas[elementosActuales].palabra,pal);
      return 0;
    }
  }
  entradas[elementosActuales].total = 0;
  entradas[elementosActuales].lineas[0] = linea;
  strcpy(entradas[elementosActuales].palabra,pal);
  ///printf("%s\n", "por aca");
  return 1;

}

void imprime(Entrada entradas[max_entradas],int n){
  for(int i=0;i<n;i++){
    printf("%s aparece %d veces en las lineas ->", entradas[i].palabra,entradas[i].total);
    for(int j=0;j<10;j++){
      printf("%d,", entradas[i].lineas[j]);
    }
    printf("\n");
  }
}

typedef struct Entrada Entrada;

int main() {
  Entrada entradas[max_entradas] = {}; /* inicializa el arreglo */
  char *linea;
  int posicionActual = 0;
  int lin = 0;
  size_t tamanio;
  while (getline(&linea,&tamanio, stdin) != -1) {
    char palabras[100][21];
    int len = split(linea,palabras);
    int i;
    for (i = 0; i < len; i++){
      //printf("palabra %d = %s\n",i,palabras[i]);
      int a = agrega(entradas,palabras[i],posicionActual,lin);
      if(a==1){
        //printf("%s\n", "Nuevo");
        posicionActual++;
      }
    }
    lin++;
  }
  imprime(entradas,posicionActual);
}
