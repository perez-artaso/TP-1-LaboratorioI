#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[80];
    char genero[80];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[400];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula();

/**
 *  Modifica una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @return -
 */
void generarPagina();

#endif // FUNCIONES_H_INCLUDED

