/***************************************************************************************
* Programa: Calculadora Básica.
* Objetivo:
     Ingresar dos números y calcular suma, resta, multiplicación, división y factorial.
*
* Version: 0.1 del 06 Abril de 2017
* Autor: Ignacio Perez Artaso
*
***************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    float x=0, y=0, r; //r será la variable que almacene lo que devuelva una función (sólo se usó para la resta).
    int opcion=0;


    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=%.2f)\n", x);
        printf("2- Ingresar 2do operando (B=%.2f)\n", y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\nOperacion a realizar: \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                system("cls");
                printf("Ingrese El Primer Operando\n");
                scanf("%f", &x);
                system("cls");

                break;
            case 2:

                system("cls");
                printf("Ingrese El Segundo Operando\n");
                scanf("%f", &y);
                system("cls");

                break;
            case 3:
                system("cls");
                suma(x, y);
                break;
            case 4:
                system("cls");
                r=resta(x, y);
                printf("%.2f - %.2f = %.2f\n", x, y, r);

                break;
            case 5:
                system("cls");
                division(x, y);
                break;
            case 6:
                system("cls");
                multiplicacion(x, y);
                break;
            case 7:
               system("cls");
               factorial(x);
               factorial(y);
                break;
            case 8:
                system("cls");
                suma(x, y);
                r=resta(x, y);
                printf("%.2f - %.2f = %.2f\n", x, y, r);
                division(x, y);
                multiplicacion(x, y);
                factorial(x);
                factorial(y);
                break;
            case 9:
                system("cls");
                seguir = 'n';
                printf("HASTA LUEGO!\n");
                break;
        }



}
return 0;
}
