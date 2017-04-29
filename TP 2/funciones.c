#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

 void inicializarLista (EPersona lista[], int tam, int valor)
 {
     int i;
     for (i=0; i<tam; i++)
     {
         lista[i].estado = valor;
     }
 }

 int obtenerEspacioLibre(EPersona lista[], int tam, int valorBuscado)
 {
     int i;
     for (i=0; i<tam; i++)
     {
         if(lista[i].estado == valorBuscado)
         {
             return i;
         }
     }

     return -1;
 }


void cargarPersona (EPersona lista[], int indice)
{
    int validar;
    char auxNumStr[10];


    if(indice != -1)
    {
        system("cls");
        printf("\nAGREGAR PERSONA\n---------------\n");
        printf("Indique El Nombre De La Persona:\n");
        fflush(stdin);
        scanf("%[^\n]", lista[indice].nombre);
        validar = validarLetras(lista[indice].nombre);
        while(validar != 1)
        {
            system("cls");
            printf("\nERROR\n---------------------------------------------\nEl Nombre Debe Constar Unicamente De Letras\n---------------------------------------------\n");
            printf("Indique El Nombre De La Persona:\n");
            fflush(stdin);
            scanf("%[^\n]", lista[indice].nombre);
            validar = validarLetras(lista[indice].nombre);
        }
        system("cls");
        printf("\nAGREGAR PERSONA\n---------------\n");
        printf("Indique La Edad De La Persona:\n");
        scanf("%s", auxNumStr);
        while(validarNumeros(auxNumStr) == 0)
        {
            system("cls");
            printf("\nERROR\n---------------------------------------------\nLa Edad Debe Expresarse En Caracteres Numericos [0 - 9]\n---------------------------------------------\n");
            printf("Indique La Edad De La Persona:\n");
            scanf("%s", auxNumStr);

        }
        lista[indice].edad = atoi(auxNumStr);

        system("cls");
        printf("\nAGREGAR PERSONA\n---------------\n");
        printf("Indique El DNI De La Persona [Limitese A Utilizar Numeros]:\n");
        scanf("%s", auxNumStr);
        while(validarNumeros(auxNumStr) == 0)
        {
            system("cls");
            printf("\nERROR\n---------------------------------------------\nEl DNI Debe Expresarse En Caracteres Numericos [0 - 9]\n---------------------------------------------\n");
            printf("Indique El DNI De La Persona:\n");
            scanf("%s", auxNumStr);

        }
        lista[indice].dni = atoi(auxNumStr);

        lista[indice].estado = 1;
        system("cls");

        printf("Persona Cargada Con Exito !");




    }
    else
    {
        system("cls");
        printf("Base De Datos Completa.\nSi Quiere Ingresar Los Datos De Otra Persona, Debe Dar De Baja A Alguna Otra (Opcion 2).");

    }

     fflush(stdin);
     scanf("%[^\n]");

}

void bajaPersona (EPersona lista[], int tam, int valor)
{
    int i, auxDNI, bandera=0;
    char opcion;
    system("cls");

    printf("Ingrese El DNI De La Persona A Eliminar: \n");
    scanf("%d", &auxDNI);

    for(i=0; i<tam; i++)
    {
        if(auxDNI == lista[i].dni && lista[i].estado == 1)
        {
            system("cls");
            printf("---------------------------------\nELIMMINAR DEL REGISTRO\n---------------------------------");
            printf("\nNombre: %s\nEdad: %d\nDNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
            printf("\nEsta Seguro Que Desea Eliminar A Esta Persona Del Registro? [s/n]\n");
            fflush(stdin);
            scanf("%c", &opcion);
            while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N')
            {
                system("cls");
                printf("ERROR. Ingrese [s] Por 'Si' o [n] Por 'No'.\n");
                printf("---------------------------------\nELIMMINAR DEL REGISTRO\n---------------------------------");
                printf("\nNombre: %s\nEdad: %d\nDNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
                printf("\nEsta Seguro Que Desea Eliminar A Esta Persona Del Registro? [s/n]\n");
                scanf("%c", &opcion);
            }
            if(opcion == 's' || opcion == 'S')
            {
                lista[i].estado = valor;
                system("cls");
                printf("Registro Eliminado Con Exito !\n");
            }
            else
            {
                system("cls");
                printf("Accion Cancelada Por El Usuario.\n");
            }
            bandera=1;
        }

    }
    if (bandera == 0)
    {
        system("cls");
        printf("[Registro No Encontrado]\n----El DNI Ingresado No Coincide Con Ninguna Persona En La Base De Datos-----\n");
    }
     fflush(stdin);
     scanf("%[^\n]");
}

void imprimirLista (EPersona lista[], int tam)
{
    int i, j;
    EPersona auxStruct;
    system("cls");

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[j].nombre, lista[i].nombre) < 0)
            {
                auxStruct = lista[i];
                lista[i] = lista[j];
                lista[j] = auxStruct;
            }
        }
    }
    printf("---------------------------REGISTRO DE PERSONAS---------------------------\n");

    for(i=0; i<tam; i++)
    {

        if(lista[i].estado == 1)
        {


        printf("\n---------------------------------\nNombre: %s\nEdad: %d\nDNI: %d\n---------------------------------\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
    fflush(stdin);
    scanf("%[^\n]");
}
  // El enunciado dice "Menores de 18". Pero considerando que la otra categoría es "Entre 19 y 35",      //
 //  si tomara en cuenta sólo a los menores de 18, a los que están entre 19 y 35 y a los mayores de 35, //
//   las personas con 18 años no figurarín en el gráfico. Se verían excluidas de toda categoría.       //
void graficarEdades (EPersona lista[], int tam)
{
    int i, mayorCant, bandera=0;
    int acum18=0, acum19=0, acum35=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].edad <= 18 && lista[i].estado == 1)
        {
            acum18++;
            continue;
        }
        else if(lista[i].edad >= 19 && lista[i].edad <= 35 && lista[i].estado == 1)
        {
            acum19++;
            continue;
        }
        else if(lista[i].edad >= 35 && lista[i].estado == 1)
        {
            acum35++;
            continue;
        }

    }

    if(acum18 >= acum19 && acum18 >= acum35)
    {
        mayorCant = acum18;
    }
    else if(acum19 >= acum18 && acum19 >= acum35 )
    {
        mayorCant = acum19;
    }
    else
    {
        mayorCant = acum35;
    }

    system("cls");

    printf("---------------------------------\nGRAFICO DE EDADES\n---------------------------------\n");

    for(i=mayorCant; i>0; i--)
    {
        printf("%02d|", i);

        if(acum18 >= i)
        {
            printf("*");
        }
        if(acum19 >= i)
        {
            printf("\t*");
            bandera=1;
        }
        if(acum35 >= i)
        {
            if(bandera == 0)
            {
                printf("\t\t*");
            }
            else
            {
                printf("\t*");
            }
        }
        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35\n");

    fflush(stdin);
    scanf("%[^\n]");


}

