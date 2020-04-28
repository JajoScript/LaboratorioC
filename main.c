#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variables globales
char nombres[20][20];

//Structura de nodo
struct Nodo{
    char info;
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
       
    }
    return aux;
}
//-------------------------------------------------------------------
Lista Lista_INSERTA_PRINCIPIO(Lista L, char x)
{
    Lista pNodo;

    pNodo = Lista_CREA_NODO(x);
    pNodo->sig = L;
    L = pNodo;
    pNodo = NULL;
    return L;
}
Lista Lista_INSERTA_FINAL(Lista L, char x)
{
    Lista pNodo, aux;

    pNodo = Lista_CREA_NODO(x);
    if (L == NULL)
        L = pNodo;
    else
    {
        aux = L;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = pNodo;
        aux = NULL;
    }
    pNodo = NULL;
    return L;
}
Lista Lista_INSERTA_EN_POSICION(Lista L, char x, int pos)
{
    Lista pNodo, aux;
    int i, largo;

    largo = Lista_LARGO(L);
    pNodo = Lista_CREA_NODO(x);
    if (pos <= largo+1) //Si p es válido para el largo de la lista.
    {
        if (pos == 1)	//Inserta en la primera posición.
            L = Lista_INSERTA_PRINCIPIO(L, x);
        else
        {
            if (pos == largo+1)           //Inserta en la última posición.
                L = Lista_INSERTA_FINAL(L, x);
            else
            {
                aux = L;
                i = 1;
                while (i < pos-1)
                {
                    aux = aux->sig;
                    i = i+1;
                }
                pNodo->sig = aux->sig;
                aux->sig = pNodo;
                aux = NULL;
            }
        }
    }
    pNodo = NULL;
    return L;
}

Lista Lista_INSERTA_ORDENADO(Lista L, char x)
{
    Lista pNodo, aux1, aux2;

    pNodo = Lista_CREA_NODO(x);
    if (L == NULL)
        L = pNodo;
    else
    {
        if (x < L->info) //Inserta al principio de L.
        {
            pNodo->sig = L;
            L = pNodo;
        }
        else
        {		//2 ó más Nodos, o inserción al final.
            aux1 = L;
            while ((aux1 != NULL) && (aux1->info < x))
            {
                aux1 = aux1->sig;
            }
            aux2 = L;
            while (aux2->sig != aux1)
                aux2 = aux2->sig;
            aux2->sig = pNodo;
            pNodo->sig = aux1;
            aux1 = NULL;
            aux2 = NULL;
        }
    }
    pNodo = NULL;
    return L;
}
Lista Lista_ELIMINA(Lista L, int p)
{
    int cont = 1;
    Lista aux, aux2;

    aux = L;
    if (p == 1)
    {
        L = L->sig;
        aux->sig = NULL;
        free(aux);
    }
    else
    {
        while (cont < p-1)
        {
            aux = aux->sig;
            cont++;
        }
        aux2 = aux->sig;
        aux->sig = aux2->sig;
        aux2->sig = NULL;
        free(aux2);
    }
    return L;
}
int Lista_LARGO(Lista L)
{
    Lista aux;
    int cont = 0;

    aux = L;
    while(aux != NULL)
    {
        aux = aux->sig;
        cont++;
    }
    return cont;
}
//-------------------------------------------------------------
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
//-------------------------------------------------------------


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

// Almacenamiento.
void almacenarRuts(char *token){
  printf("rut %s", token);
}

// Manejo de archivos.
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
        almacenarRuts(token);

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

// __init__
int main(void){
  // Variables locales.
  char *archivo = (char *)malloc(1);
  char *archivoSalida = (char *)malloc(1);

  archivo = ingresoArchivo(0);
  archivoSalida = ingresoArchivo(1);
  leerProblema(archivo);  // input.csv
  

  // Escritura de archivos.
  // escribirResultados(archivoSalida, "Manolo estuvo aqui!");

  //funcion lista enlazada  (creacion de lista )
  // Lista L;
  // L = Lista_INICIALIZA();
  // char valor = 'a';
  // int pos = 1;
  // if (pos <= Lista_LARGO(L)+1){
  //     L = Lista_INSERTA_EN_POSICION(L, valor, pos);
  // }
  
  // Lista_IMPRIME(L);



}