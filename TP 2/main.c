/******************************************************************
* Programa: Registro De Personas
*
*   Objetivo:
*       Desarrollar un programa que permita almacenar en una base
*       de datos el nombre, edad y DNI de las personas que se desee.
*
*   Datos de cada persona:
*       - Nombre (Máximo 49 Caracteres)
*       - Edad
*       - DNI
*
*
*   1. Agregar Persona.
*   2. Borrar Persona.
*   3. Imprimir Lista (Por Orden Alfabético).
*   4. Imprimir Gráfico De Edades.
*
*
* Version: 0.1 del 28/4/2017
* Autor: Ignacio Perez Artaso
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define CANT_MAX 20


int main()
{
    char seguir='s';
    int opcion=0;
    int posLibre;

    EPersona lista[CANT_MAX];

    inicializarLista (lista, CANT_MAX, 0);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                posLibre = obtenerEspacioLibre(lista, CANT_MAX, 0);
                cargarPersona (lista, posLibre);

                break;
            case 2:
                bajaPersona (lista, CANT_MAX, 0);
                break;
            case 3:
                imprimirLista (lista, CANT_MAX);
                break;
            case 4:
                graficarEdades (lista, CANT_MAX);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    system("cls");
    printf("HASTA LUEGO !\n");

    return 0;
}
