#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Carga secuencialmente todos las variables en una estructura ubicada en el array.
 * @param lista el array se pasa como parametro.
 * @param indice indica la posicion de la estructura a utilizar en el array.
 */
void cargarPersona (EPersona lista[], int indice);

/**
 * Busca por DNI (en tanto código irrepetible) a la persona y, de encontrarla, cambia su estado al valor que se indique.
 * @param lista el array se pasa como parametro.
 * @param tam indica el tamaño que tendrá el array de estructuras.
 * @param valor es el número que se cargará en la variable estado.
 */
void bajaPersona (EPersona lista[], int tam, int valor);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro
 * @param tam indica el tamaño que tendrá el array de estructuras.
 * @param valorBuscado indica qué valor de estado (en este caso) estoy buscando.
 * @return el primer indice disponible / -1 en caso de no haber ninguno.
 */

 /**
 * Ordena alfabéticamente y por burbujeo las estructuras contenidas
 * en el array según su nombre y luego imprime los datos de todas las estructuras.
 * @param lista el array se pasa como parametro.
 * @param tam indica el tamaño del array (la cantidad de elementos a recorrer).
 */
 void imprimirLista (EPersona lista[], int tam);

int obtenerEspacioLibre(EPersona lista[], int tam, int valorBuscado);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam indica el tamaño que tendrá el array de estructuras.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Carga un valor indicado en cada variable estado de las estructuras en el array.
 * @param lista el array se pasa como parametro.
 * @param tam indica el tamaño del array (la cantidad de elementos a recorrer).
 * @param valor es el número que se cargará en la variable estado.
 */
 void inicializarLista (EPersona lista[], int tam, int valor);

 /**
 * Imprime un gráfico de barras que indica la distribución de las edades que figuran
 * en las estructuras del array a partir de tres categorías (menores de 18, entre 19 y 35, mayores de 35).
 * @param lista el array se pasa como parametro.
 * @param tam indica el tamaño del array (la cantidad de elementos a recorrer).
 */
 void graficarEdades (EPersona lista[], int tam);
#endif // FUNCIONES_H_INCLUDED
