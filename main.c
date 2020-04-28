#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variables globales
char nombres[20][20];

//Structura de nodo
struct Nodo{
    int info;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;

//Construccion de lista (acá debe ir el rut de la persona)
Lista Lista_INICIALIZA(void)
{
    return NULL;
}

Lista Lista_CREA_NODO(char valor)
{
    Lista aux;

    aux = (Lista)malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->info = valor;
        aux->sig = NULL;
    }
    else
    {
        system("cls");
       
    }
    return aux;
}

void Lista_IMPRIME(Lista L)
{
    Lista aux;

    aux = L;
    printf("\n\n\tL -> ");
    while(aux != NULL)
    {
        printf("%d -> ", aux->info);
        aux = aux->sig;
    }
    printf("NULL");

}


void escribirResultados(const char *nombre_archivo, char *info){
  FILE * archivo;
  archivo = fopen(nombre_archivo, "w");

  // Verificacion del archivo.
  if(archivo == NULL){
    printf("No se puede abrir el fichero.\n");
    return;
  }

  // Escritura
  fputs(info, archivo);
  fclose(archivo);
  printf("Se escribio en el archivo!");
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

  // Escritura de archivos.
  escribirResultados(archivoSalida, "Manolo estuvo aqui!");

   
   
   
   
   //funcion lista enlazada
 /* Lista L;
  L = Lista_INICIALIZA();
  valor = 'c';
  pos = LeePosicion();
      if (pos <= Lista_LARGO(L)+1)
                L = Lista_INSERTA_EN_POSICION(L, valor, pos);*/



}