#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int validarLetras(char texto[])
{
    int length, i;
    length = strlen(texto);

    for(i=0; i<length; i++)
    {
        if (texto[i] != ' ' && (texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z') )
        {
            return 0;
        }
    }
    return 1;
}

int validarNumeros(char numero[])
{
    int i;
    i=0;
    while(numero[i] != '\0')
    {
        if(numero[i] < '0' || numero[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;

}

