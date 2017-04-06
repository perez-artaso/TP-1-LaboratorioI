#include <stdio.h>
#include <stdlib.h>
/** FUNCIÓN SUMA
* \brief Toma dos números, los suma e imprime el resultado por consola.
* \param a Es el primer operando que recibe.
* \param b Es el segundo operando que recibe.
* \return No devuelve nada (ver aclaración en Encabezados).
*
*/
void suma (float a, float b){

    float total;

    total=a+b;
    printf("%.2f + %.2f = %.2f\n", a, b, total);


}
/** FUNCIÓN RESTA
* \brief Toma dos números y le resta el segundo al primero.
* \param a Es el primer operando que recibe.
* \param b Es el segundo operando que recibe.
* \return Devuelve el resultado de la resta.
*
*/
float resta (float a, float b){

    float total;
    total=a-b;
    return total;
}
/** FUNCIÓN DIVISION
* \brief Toma dos números, los divide e imprime el resultado por consola.
* \param a Es el primer operando que recibe.
* \param b Es el segundo operando que recibe.
* \return Devuelve el resultado de la división.
*
*/
float division (float a, float b){
    float total;
     if(b==0){

                    printf("%.2f / %.2f = ERROR (No Puede Dividir Por Cero)\n", a, b);

        }
     else{
                     total=a/b;
                     printf("La Division De Los Operandos Es: %.2f\n", total);

        }
    return total;
}
/** FUNCIÓN MULTIPLICACION
* \brief Toma dos números, los multiplica e imprime el resultado por consola.
* \param a Es el primer operando que recibe.
* \param b Es el segundo operando que recibe.
* \return Devuelve el resultado de la multiplicación.
*
*/
float multiplicacion (float a, float b){

    float total;
    total=a*b;
    printf("%.2f * %.2f = %.2f\n", a, b, total);
    return total;
}
/** FUNCIÓN FACTORIAL
* \brief Toma un número, calcula su factorial y lo imprime por consola.
* \param a Es el operando que recibe.
* \return Devuelve el factorial del operando recibido.
*
*/
float factorial (float a){
    int i; //contador de vueltas, debe llegar hasta el número ingresado.
    float fac=1; //inicializado en 1 porque será un acumulador de multiplicaciones y porque 0!=1.
                if(a<0){
                    printf("No Se Pudo Factorializar El Operando %.2f (Debe Ser Positivo).\n", a);
                }
                else{
                for(i=1; i<=a; i++){
                    fac=fac*i;
                    }
                    printf("El Factorial Del Operando %.2f Es %.2f\n", a, fac);

                }
return fac;
}
