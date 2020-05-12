/*
  Autores: Javier Almarza y Vicente Salas.
*/

// Dependencias.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estructuras.
// __NODO__
struct Nodo{
  int info;
  struct Nodo *sig;
};
typedef struct Nodo tNodo;

//Tipo "Lista" que será un puntero a un nodo de la lista
// __LISTA__
typedef tNodo *Lista;

// Funciones para las listas.
Lista Lista_INICIALIZA(void){ return NULL; };

Lista Lista_CREA_NODO(int valor){
    Lista aux;

    aux = (Lista)malloc(sizeof(tNodo));
    if (aux != NULL){
      aux->info = valor;
      aux->sig = NULL;
    }
    else {
      system("cls");
      printf("\n\tERROR: No hay memoria suficiente para generar un nuevo Nodo.");
    }
     
    return aux;
};

Lista Lista_INSERTA_PRINCIPIO(Lista L, int valor){
    Lista pNodo;

    pNodo = Lista_CREA_NODO(valor);
    pNodo->sig = L;
    L = pNodo;
    pNodo = NULL;
    return L;
};

Lista Lista_INSERTA_FINAL(Lista L, int valor){
    Lista pNodo, aux;

    pNodo = Lista_CREA_NODO(valor);
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

int Lista_LARGO(Lista L){
    
    Lista aux;
    int cont = 0;
    aux = L;
    while(aux != NULL){
        aux = aux->sig;
        cont++;
    }
    return cont;
}

Lista Lista_INSERTA_ORDENADO(Lista L, int valor){
    
    Lista pNodo, aux1, aux2;
    pNodo = Lista_CREA_NODO(valor);
    if (L == NULL)
        L = pNodo;
    else
    {
        if (valor < L->info) //Inserta al principio de L.
        {
            pNodo->sig = L;
            L = pNodo;
        }
        else
        {		//2 ó más Nodos, o inserción al final.
            aux1 = L;
            while ((aux1 != NULL) && (aux1->info < valor))
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

Lista Lista_INSERTA_EN_POSICION(Lista L, int valor, int posicion){
  Lista pNodo, aux;
  int largo;

  largo = Lista_LARGO(L);
  pNodo = Lista_CREA_NODO(valor);
    
  if (posicion <= largo+1){ //Si p es válido para el largo de la lista.
    if (posicion == 1){ //Inserta en la primera posición.
      L = Lista_INSERTA_PRINCIPIO(L, valor); 
    }	else {
      if (posicion == largo+1){ //Inserta en la última posición.
        L = Lista_INSERTA_FINAL(L, valor);
      } else {
        aux = L;
        int i = 1;
          
        while (i < posicion-1){
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
};

Lista Lista_ELIMINA(Lista L, int p){
    Lista aux, aux2;

    aux = L;
    if (p == 1){
      L = L->sig;
      aux->sig = NULL;
      free(aux);
    } else {
      int cont = 1;

      while (cont < p-1) {
        aux = aux->sig;
        cont++;
      }
      
      aux2 = aux->sig;
      aux->sig = aux2->sig;
      aux2->sig = NULL;
      free(aux2);
    }

    return L;
};

int Lista_POSICION_ELEMENTO(Lista L, int x){
    Lista aux;
    int pos=0;

    aux = L;
    while (aux != NULL)
    {
        pos++;
        if (aux->info == x)
            return pos;
        aux = aux->sig;
    }
    return 0;
}

void Lista_IMPRIME(Lista L){
  Lista aux;
  aux = L;
    
  printf("\n\n\tL -> ");
  while(aux != NULL){
    printf("%d -> ", aux->info);
    aux = aux->sig;
  };

  printf("NULL");
}

// Variables globales.
int ListaDeRuts[10];
int ListaDeEntradas[10];
char ListaDeNombres[80][80];

// Funciones para el manejo de datos.
int identificador(char letra){
  // Variables locales.
  int num;

  // Condicionales para cada cifra.
  if(letra == '0'){
    num = 0;
  } else if(letra == '1'){
    num = 1;
  } else if(letra == '2'){
    num = 2;
  } else if(letra == '3'){
    num = 3;
  } else if(letra == '4'){
    num = 4;
  } else if(letra == '5'){
    num = 5;
  } else if(letra == '6'){
    num = 6;
  } else if(letra == '7'){
    num = 7;
  } else if(letra == '8'){
    num = 8;
  } else {
    num = 9;
  }; 

  // Retorno de la letra en tipo int.
  return num;
};

Lista capturarDatos(char *token, char *entradas, int iterador, Lista L){
  // Variables locales.
  int num, aux, numeroEntradas;
  int i = 0;

  // Cambiando el tipo de dato de char a int.
  // 205.812.911 <=> String token
  // 0123456789 <=> int, se tiene que omitir el [8]

  // Ciclo iterador para transformar los Ruts.
  // Según las cifras => Unidades, decenas, centenas, ...
  while(i <= 9){
    // Se omite el indice 8, ya que contiene el caracter '-'.
    if(i != 8){
      // Identificando la cifra.
      num = identificador(token[i]);
      
      // Calculando por iteraciones las cifras.
      if(i == 0){
        num = num * 100000000;
        aux = num;
      }else if(i == 1){
        num = num * 10000000;
        aux = aux + num;
      }else if(i == 2){
        num = num * 1000000;
        aux = aux + num;
      }else if(i == 3){
        num = num * 100000;
        aux = aux + num;
      }else if(i == 4){
        num = num * 10000;
        aux = aux + num;
      }else if(i == 5){
        num = num * 1000;
        aux = aux + num;
      }else if(i == 6){
        num = num * 100;
        aux = aux + num;
      }else if(i == 7){
        num = num * 10;
        aux = aux + num;
      }else if(i == 9){
        num = num * 1;
        aux = aux + num;
      };
    };
    
    // Iteración del ciclo.
    i++;
  };
  
  // Calculando las entradas.
  numeroEntradas = identificador(entradas[0]);
  
  // Agregando los rut a un vector.
  ListaDeRuts[iterador] = aux;
  ListaDeEntradas[iterador] = numeroEntradas;
  

  // Agregando los datos a la lista L.
  L = Lista_INSERTA_FINAL(L, aux);
  L = Lista_INSERTA_FINAL(L, numeroEntradas);

  return L;
};

// *** Manejo de archivos. ***
char *ingresoArchivo(int a){
  // Variables locales.
  char *file = (char *)malloc(1);
  
  // Dependiendo del valor, mostrara uno de los mensajes.
  if(a == 0){
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", file);
  }
  else {
    printf("\nIngrese el nombre del archivo de salida: ");
    scanf("%s", file);
  }

  // Retorna el nombre del archivo.
  return file;
}

void escribirResultados(const char *nombre_archivo, char *info){
  FILE * archivo;
  archivo = fopen(nombre_archivo, "a");

  // Verificacion del archivo.
  if(archivo == NULL){
    printf("No se puede abrir el fichero.\n");
    return;
  }

  // Escritura
  fputs(info, archivo);
  fclose(archivo);
  // printf("\nSe escribio en el archivo!"); [DEPURACION]
}

// Funcion ejecutadora del programa.
void leerProblema(const char *nombre_archivo){
    // Manejo de archivos.
    FILE * archivo;
    archivo = fopen(nombre_archivo, "r");

    // Creacion de la lista.
    Lista L;
    L = Lista_INICIALIZA();

    // Validación del input.
    if (archivo == NULL){
      printf( "No se puede abrir el fichero.\n" );
      return;
    } else {
      // Variables para la captura de datos.
      char linea[1000],
      delimitador[] = ",", *rut, *entradas, *nombre;
      int iterador = 0;

      // Ciclo para la captura de información.
      while( fgets (linea, 1000, archivo) != NULL ){
          rut = strtok(linea, delimitador);
          // printf("\nRUT: %s", rut); [Depuracion]
          nombre = strtok(NULL, delimitador);
          //printf("\nNOMBRE: %s", nombre); [Depuracion]
          
          // Almacenando los nombres.
          strcpy(ListaDeNombres[iterador], nombre);

          entradas = strtok(NULL, delimitador);
          // printf("\nENTRADAS: %s", entradas); [Depuracion]
          
          // Manejando la información.
          L = capturarDatos(rut, entradas, iterador, L);
          
          // printf("\n-----------------------"); [Depuracion]
          iterador++;
      };

      // Variables locales.
      int j;
      int verificacion;
      int i = 0;
      char *listaAlternativa;

      // Ciclo para determinar los nombres repetidos.
      while(i <= iterador - 1){
        listaAlternativa = ListaDeNombres[i];
        // printf("\nNOMBRE NOMBRE:%s", listaAlternativa);

        j = i + 1;
        while(j <= iterador-1){
          verificacion = memcmp(listaAlternativa,ListaDeNombres[j], 80);
          if (verificacion == 0){
            strcpy(ListaDeNombres[j], ListaDeNombres[j + 1]);
          };
          j++;
        };
        i++;
      };
    };
  
    // Variables locales.
    int posicion, posicion2;
    int usuario = 0;
    int entradasTotales = 0; 
    int num;

    // Listas paralelas.
    Lista L_registrados;
    L_registrados = Lista_INICIALIZA();
    Lista L_entradas;
    L_entradas = Lista_INICIALIZA(); 
    Lista L_nombres;
    
    Lista L_auxiliar;
    L_auxiliar = Lista_INICIALIZA();

    while(usuario <= 5){
      posicion = Lista_POSICION_ELEMENTO(L, ListaDeRuts[usuario]);
      if(posicion != 0){
       // printf("\nEl elemento %d se encuentra en la lista.", ListaDeRuts[usuario]) DEPURACION;

        if(entradasTotales == 0){
          if(ListaDeEntradas[usuario] > 2){
            entradasTotales = 2;
          }else {
            entradasTotales = ListaDeEntradas[usuario];
          }
         // printf("\nEl usuario tiene %d nuevas entradas", entradasTotales) DEPURACION;
        }else{
          entradasTotales = entradasTotales + ListaDeEntradas[usuario];
         // printf("\nEl usuario tiene %d en total", entradasTotales);

          // Verificacion de entradas.
          if(entradasTotales <= 2){
           //printf("\nEl usuario puede comprar las entradas");
          }else if(entradasTotales > 2){
           // printf("\nEl usuario solo puede 2 comprar las entradas, no %d", entradasTotales);
            entradasTotales = 2;
          }
          else {
           // printf("\nEl usuario no puede comprar las entradas");
          }
        }
        // Eliminarlo.
        L = Lista_ELIMINA(L, posicion);
        
       // Lista_IMPRIME(L) DEPURACION;
      }else {
        // Buscando si se encuentra registrado.
        posicion2 = Lista_POSICION_ELEMENTO(L_registrados, ListaDeRuts[usuario]);
        
        if(posicion2 != 0){
          usuario++;

          if(entradasTotales > 0){
           // printf("\nEl usuario finalmente tiene %d entradas", entradasTotales);

            L_entradas = Lista_INSERTA_FINAL(L_entradas, entradasTotales); // EntradasVicente

           // printf("\n------------");
           // Lista_IMPRIME(L_registrados);
           // Lista_IMPRIME(L_entradas);
           // printf("\n------------");

            entradasTotales = 0;
           // printf("\nSaltando al siguiente usuario");
          }
          
        }else{
          // Registrarlo.
          L_registrados = Lista_INSERTA_FINAL(L_registrados, ListaDeRuts[usuario]); // vicente
         // printf("\nEl elemento ahora se encuentra en la lista registrado.");
        };
      };
    };

    // Declarando el archivo de salida.
    char *archivoSalida = (char *)malloc(1);  
    archivoSalida = ingresoArchivo(1);

    // Contenedores.
    char rutString[100];
    char nombreString[100];
    char entradaString[100];
    
    // Variables para el ciclo.
    int largo;
    int iteradora = 1;
    int nombreiteracion = 0;

    // Listas auxiliares.
    Lista aux;
    aux = L_registrados;
    
    Lista aux2;
    aux2 = L_entradas;

    Lista aux3;
    aux3 = L_nombres;

    largo = Lista_LARGO(L_registrados);
    //printf("\nLo que queremos transformar:\n");
    while(iteradora <= largo){
      // printf("%d ", aux->info);

      // Escribir ruts.
      sprintf(rutString, "%d,", aux->info);
      escribirResultados(archivoSalida, rutString);

      // Escribir nombres.
      sprintf(nombreString, "%s,", ListaDeNombres[nombreiteracion]);
      escribirResultados(archivoSalida, nombreString);

      // Escribir las entradas.
      sprintf(entradaString, "%d\n", aux2->info);
      escribirResultados(archivoSalida, entradaString);

      
      // Iteracion;
      aux = aux->sig;
      aux2 = aux2->sig;
      nombreiteracion++;
      iteradora++;
    };
    
    //printf("\nListo!, se guardaron los resultados.");

    // Cerrando el archivo.  
    fclose(archivo);
};

// __init__
int main(void){
  // Variables locales.
  char *archivo = (char *)malloc(1);

  // Ingreso de datos.
  archivo = ingresoArchivo(0);
  leerProblema(archivo);  // input.csv
  
  return 0;
};