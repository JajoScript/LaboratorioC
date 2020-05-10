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
  int i, largo;

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
        i = 1;
          
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
    int cont = 1;
    Lista aux, aux2;

    aux = L;
    if (p == 1){
      L = L->sig;
      aux->sig = NULL;
      free(aux);
    } else {
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
void CreacionCasillas(int rut, int numeroEntradas, int iterador){
    Lista L;
    L = Lista_INICIALIZA();
    L = Lista_INSERTA_EN_POSICION(L, rut, iterador);
    L = Lista_INSERTA_EN_POSICION(L, numeroEntradas,iterador+1);
    //  L -> 123334442 -> 2 -> NULL
    //        [1] -> [2] iterador = 1
    //        [3] -> [4] iterador = 3

    Lista_IMPRIME(L);
};

// Manejo de datos.
int identificador(char letra){
  // Variables.
  int num;

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
  } else if(letra == '9'){
    num = 9;
  }; 

  // printf("\nNumero vale: %d", num);
  return num;
}

void capturarDatos(char *token, char *entradas, int iterador){
  // Variables.
  int num, aux, numeroEntradas;

  // Cambiando el tipo de dato de char a int.
  // 205.812.911 <=> String token
  // 0123456789 <=> int, se tiene que omitir el [8]
  int i = 0;
  while(i <= 9){
    if(i != 8){
      num = identificador(token[i]);
      
      // Calculando por iteraciones.
      if(i == 0){
       
        num = num * 100000000;
        // Asignacion incial.
        aux = num;
       
      }else if(i == 1){
       
        num = num * 10000000;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 2){
       
        num = num * 1000000;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 3){
        
        num = num * 100000;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 4){
        
        num = num * 10000;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 5){
        
        num = num * 1000;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 6){
        
        num = num * 100;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 7){
        
        num = num * 10;
        // Aritmetica
        aux = aux + num;
        
      }else if(i == 9){
        
        num = num * 1;
        // Aritmetica
        aux = aux + num;
        
      };
    };

    i++;
  };
  
  // Calculando las entradas.
  numeroEntradas = identificador(entradas[0]);
  printf("\nNumero de entradas: %d", numeroEntradas);
  printf("\nInicio: String %s", token);
  printf("\nFinal: int %d", aux);
  
  CreacionCasillas(aux, numeroEntradas, iterador);

};

// Manejo de archivos.
void leerProblema(const char *nombre_archivo){
    FILE * archivo;
    char linea[1000],
    delimitador[] = ",",
    *rut, *entradas, *nombre;

    archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL){
      printf( "No se puede abrir el fichero.\n" );
      return;
    }

    int iterador = 1;
    while( fgets (linea, 1000, archivo) != NULL ){
        rut = strtok(linea, delimitador);
        printf("\nRUT: %s\n", rut);
        

        nombre = strtok(NULL, delimitador);
        printf("\nNOMBRE: %s\n", nombre);
        
        entradas = strtok(NULL, delimitador);
        printf("\nENTRADAS: %s\n", entradas);

        capturarDatos(rut, entradas, iterador);
        iterador = iterador + 2;


        printf("\n-----------------------\n");
    };
};

char *ingresoArchivo(int a){
  // variables locales.
  char *file = (char *)malloc(1);
  
  if(a == 0){
    printf("Ingrese el nombre del archivo: input.csv \n");
    file = "input.csv"; // scanf("%s", file);
  }
  else {
    printf("Ingrese el nombre del archivo de salida: manolo.txt \n");
    file = "manolo.txt"; // scanf("%s", file);
  }

  return file;
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

// __init__
int main(void){
  // Variables locales.
  char *archivo = (char *)malloc(1);
  char *archivoSalida = (char *)malloc(1);  
  
  // Ingreso de datos.
  archivo = ingresoArchivo(0);
  archivoSalida = ingresoArchivo(1);
  leerProblema(archivo);  // input.csv
  
  

  

  // Escritura de archivos.

}
