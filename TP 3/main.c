/***************************************************************************************
* Programa: Base De Datos: Peliculas.
* Objetivo:
     Generar una base de datos que permita guardar los datos de distintas peliculas,
     eliminarlos, modificarlos y exportarlos a un archivo de extensi�n html.

* Caracter�sticas:
     El desarrollo del programa apunt� hacia la consecusi�n de la mayor simplicidad
     combinada con la mayor eficiencia. La funci�n que agrega una pelicula al registro
     trabaja con una variable de tipo struct declarada en main, y llevada a la funci�n
     v�a referencia. Otro aproximamiento posible es declarar un auxiliar por cada campo de
     la estructura dentro de la funci�n. Esto se utiliz� en las funciones de borrar y modificar
     pelicula. La funci�n que genera el archivo html trabaja con una estructura auxiliar en
     la que se vuelca cada elemento del archivo binario, leido de a uno por la funci�n fread
     y llevado al archivo html a trav�s de la funci�n fprintf. Otra aproximaci�n posible es
     la utilizaci�n de un array de estructuras, cuya longitud fuese determinada por las funciones
     de manipulaci�n din�mica de memoria, en el cual se volcar�an todos los elementos contenidos
     por el archivo binario de una vez, tanto para ser modificados en el segmento heap de la memoria
     como para ser exportados de una vez. Sin embargo, considerando que la base de datos puede contener
     una cantidad enorme de elementos, en el presente programa se opt� por la metodolog�a antes
     descripta.
*
*
* Version: 0.1 del 02 Junio de 2017
* Autor: Ignacio Perez Artaso
*
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{

    EMovie movie;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf(" ------------------------\n|BASE DE DATOS: PELICULAS|\n ------------------------\n\n\n\n");
        printf("\t1- Agregar pelicula\n");
        printf("\t2- Borrar pelicula\n");
        printf("\t3- Modificar pelicula\n");
        printf("\t4- Generar pagina web\n");
        printf("\t5- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(&movie);
                break;
            case 2:
                borrarPelicula();
                break;
            case 3:
                modificarPelicula();
               break;
            case 4:
                generarPagina();
                break;
            case 5:
                seguir = 'n';
                system("cls");
                printf("HASTA LUEGO !");
                break;
            default:
                system("cls");
                printf("ERROR. El valor ingresado no corresponde a ninguna opcion de este programa.\n\n\n\n");
                system("pause");

        }
    }

    return 0;
}
