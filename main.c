// Dependencias.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variable global.
int ListaDeRuts[10];

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
  } else {
    num = 9;
  }; 

  return num;
}

Lista capturarDatos(char *token, char *entradas, int iterador, Lista L){
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

    i++;
  };
  
  // Calculando las entradas.
  numeroEntradas = identificador(entradas[0]);
  
  // Agregando los rut a un vector.
  ListaDeRuts[iterador] = aux;

  // Agregando los datos a la lista L.
  L = Lista_INSERTA_FINAL(L, aux);
  L = Lista_INSERTA_FINAL(L, numeroEntradas);

  return L;
};

// Manejo de archivos.
void leerProblema(const char *nombre_archivo){
    FILE * archivo;
    archivo = fopen(nombre_archivo, "r");

    // Creacion de la lista.
    Lista L;
    L = Lista_INICIALIZA();

    if (archivo == NULL){
      printf( "No se puede abrir el fichero.\n" );
      return;
    }else {
      

      // Variables para la captura de datos.
      char linea[1000],
      delimitador[] = ",", *rut, *entradas, *nombre;

      int iterador = 0;
      while( fgets (linea, 1000, archivo) != NULL ){
          rut = strtok(linea, delimitador);
            printf("\nRUT: %s", rut);
          nombre = strtok(NULL, delimitador);
            printf("\nNOMBRE: %s", nombre);
          entradas = strtok(NULL, delimitador);
            printf("\nENTRADAS: %s", entradas);
          
          // Manejando la información.
          L = capturarDatos(rut, entradas, iterador, L);
          
          printf("\n-----------------------");
          iterador = iterador + 1;
      };
    };
    
    // Lista la lista.
    Lista_IMPRIME(L);
    
    // Mostrar lista de ruts. (DEPURACION)
    int i = 0;
    printf("\n");
    while(i <= 5){
      printf("%d,", ListaDeRuts[i]);
      i++;
    }printf("\n");
    
    // Necesitamos identificar a cada comprador.
    // L -> rut -> entradas -> rut2 -> entradas2
    // Creamos una Lista paralela.
    // Lista Registrados. (almacenara el rut como identificador )
    // Registrados -> rut -> entradas_registrado (el nodo siguiente sera el numero de entradas que quiere comprar. )
    // Una vez este registrado debemos eliminar el Nodo rut y entradas de la lista L.
    // Ahora que el nodo no esta en la lista buscamos si se encuentra otra vez en la lista L.
    // Si esta en la lista se elimina el rut y se mira el nodo siguiente (entradas.) y se verifica si puede adquirir mas entradas o si supero el tope.
    
    // Variables.
    int posicion, posicion2;
    int usuario = 0;

    // Listas paralelas.
    Lista L_registrados;
    Lista L_entradas;

    // Buscando a los weones.
    posicion = Lista_POSICION_ELEMENTO(L, ListaDeRuts[usuario]); // 1 1 0
    
    if(posicion != 0){
      printf("\nEl elemento se encuentra en la lista.");
      
      // Eliminarlo.
      L = Lista_ELIMINA(L, posicion);
      Lista_IMPRIME(L);
    }else {
      // Buscando si se encuentra registrado.
      posicion2 = Lista_POSICION_ELEMENTO(L_registrados, ListaDeRuts[usuario]);

      if(posicion2 != 0){
        usuario++;
      }else{
        // Registrarlo.
        L_registrados = Lista_INSERTA_FINAL(L_registrados, ListaDeRuts[0]); // vicente
        printf("\nEl elemento ahora se encuentra en la lista registrado.");
      };
    };

    // Iteracion.
    
    // Cerrando el archivo.  
    fclose(archivo);
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
  // char *archivoSalida = (char *)malloc(1);  
  
  // Ingreso de datos.
  archivo = ingresoArchivo(0);
  // archivoSalida = ingresoArchivo(1);
  leerProblema(archivo);  // input.csv
  
  

  

  // Escritura de archivos.

}
