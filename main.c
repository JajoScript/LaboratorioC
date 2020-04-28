#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variables globales
char nombres[20][20];

//creacion de nodo
struct Nodo{
    int info;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;





void escribirResultados(const char *nombre_archivo, const char *info){
  FILE * archivo;
  archivo = fopen(nombre_archivo, "r");

  // Verificacion del archivo.
  if(archivo == NULL){
    printf("No se puede abrir el fichero.\n");
    return;
  }


}

void leerProblema(const char *nombre_archivo){
    FILE * archivo;
    char linea[1000],
    delimitador[] = ",",
    *token;

    archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL){
        printf( "No se puede abrir el fichero.\n" );
        return;
    }

    while( fgets (linea, 1000, archivo) != NULL ){
        token = strtok(linea, delimitador);
        printf("RUT: %s\n", token);
        
        token = strtok(NULL, delimitador);
        printf("NOMBRE: %s\n", token);
        
        token = strtok(NULL, delimitador);
        printf("ENTRADAS: %s\n", token);
        printf("-----------------------\n");
    }
}

char *ingresoArchivo(int a){
  // variables locales.
  char *file = (char *)malloc(1);
  
  if(a == 0){
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", file);
  }
  else {
    printf("Ingrese el nombre del archivo de salida: ");
    scanf("%s", file);
  }

  return file;
}

int main(void){
  // Variables locales.
  char *archivo = (char *)malloc(1);
  char *archivoSalida = (char *)malloc(1);

  // Calls
  archivo = ingresoArchivo(0);
  archivoSalida = ingresoArchivo(1);
  // leerProblema(archivo);  // input.csv

  escribirResultados(archivoSalida, "Manolo estuvo aqui!");
}