#include <stdio.h>
#include <string.h>

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

int main(void){
  leerProblema("./input.csv");
}