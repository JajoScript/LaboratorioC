# <span><img src="sourceImgs/a.png" width="25" alt="[c logo]"></span> Laboratorio: Algoritmo y estructura de datos

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/13f922c7c8514fb295a0845687878d2e)](https://app.codacy.com/manual/JajoScript/LaboratorioC?utm_source=github.com&utm_medium=referral&utm_content=JajoScript/LaboratorioC&utm_campaign=Badge_Grade_Dashboard)
[![Run on Repl.it](https://repl.it/badge/github/JajoScript/LaboratorioC)](https://repl.it/github/JajoScript/LaboratorioC)
![GitHub contributors](https://img.shields.io/github/contributors/JajoScript/LaboratorioC?color=green)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/Jajoscript/LaboratorioC)
![GitHub last commit](https://img.shields.io/github/last-commit/JajoScript/LaboratorioC)

## Terminos de uso y condiciones
*   Este Respositorio se apropia al uso exclusivo de Javier Almarza y Vicente Salas.
*   No copien la wea giles culiaos.
*   Aún no entendemos para que piden un MakeFile.

## Pendiente
*   [x] Menejar la captura de datos.
*   [x] Almacenar cada parametro en una lista de nodos.
*   [x] Manejar la entrada y salida de archivos.
*   [x] Aplicar colas a cada insersión de la lista.
*   [ ] Identificar el limite de entradas.
*   [ ] Almacenar los usuarios que ya compraron.
*   [ ] Documentar las funciones del codigo.

## Trabajando para usted
<img src="./sourceImgs/a.gif" width="300" alt="gato trabajando" style="border:solid 5px black;">

## Enunciado
La empresa que vende las entradas a Lollapalooza va a generar una súper promoción de último minuto, en la que los clientes tendrán un descuento de 50% en el valor de la entrada. Para comprar, los interesados deberán inscribirse a través del sitio web a partir de las 00:00 del día anterior al evento. Cada persona debe indicar su rut, su nombre y las entradas que desea comprar. Solamente se puede comprar un máximo de dos entradas por persona con este descuento especial. Hay solamente 100 entradas disponibles para esta promoción. Usando un archivo de texto con los datos de cada persona que se inscribió para comprar, deberás verificar si alguien está tratando de comprar más entradas que las permitidas, y asignar las entradas respetando el orden en que las personas se inscribieron. Como resultado final tu programa debe generar un archivo que indique las personas que lograron adquirir alguna de las 100 entradas en promoción. Como puedes observar en el ejemplo de la tabla 1, hay personas que compran dos entradas y hay otras que compran solamente una.

| Representación en el archivo de texto |
|            :---:                      |
|    *12333444-2, María Reyes, 2*       |
|    *13444555-6, José Durán, 1*        |
|    *19000111-3, Pedro Díaz,1*         |
|    *13444555-6, José Durán, 2*        |
|    *20581291-1, Javier Almarza,3*     |
|    *20455114-6, Vicente Salas,4*      |

## Documentación
*   Nodos y Listas.

    ```c
    Lista Lista_INICIALIZA(void){ ... }
    ```

    *Inicializa la lista para poder ser utilizada en un momento futuro.*   

    ```c
    Lista Lista_CREA_NODO(int valor){ ... }
    ```

    *Crea un nodo que almacenara el **valor** que se le entregue.*

    ```c
    Lista Lista_INSERTA_PRINCIPIO(Lista L, int valor){ ... }
    ```

    *Crea un nodo que toma el **valor** recibido como parametro y lo inserta al comienzo de la lista **L** que se le entregue como parametro.*

    ```c
    Lista Lista_INSERTA_FINAL(Lista L, int valor){ ... }
    ```

    *Crea un nodo que toma el **valor** recibido como parametro y lo inserta al final de la lista **L** que se le entregue como parametro.*

    ```c
    int Lista_LARGO(Lista L){ ... }
    ```

    *Retorna un valor entero que corresponde al largo de la lista **L** que se le pase como parametro.*


*   Manejo de archivos.
    
    ```c
    function():
    ```
    

## Comandos para el uso de git

| Comandos   | Descripción                                                     |
| ---        | ---                                                             |
| git status | Ver la lista de archivos modificados.                           |
| git diff   | Mostrar las diferencias en los archivos que no se han agregado. |

## Contribuidores
Este proyecto existe gracias a todas las personas que contribuyen.

<img src="./sourceImgs/b.png" width="100"/>
