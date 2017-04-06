#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/**
*Aclaración general:
    Dado que las funciones, luego de calcular, imprimen el resultado, no es necesario que devuelvan nada. Así se ejemplifica
    en la FUNCIÓN suma. Sin embargo, opté por programar las demás funciones de forma tal que devulvan el resultado
    de la operación, en caso de que quisieran usarse para otros fines (además de la simple impresión del resultado). En ese
    caso, se borraría la línea de impresión (printf) en la función, y se asignaría en el main a una variable nuestra función.
    Podríamos así imprimir ésta variable o relacionarla con cualquier otra que quisieramos. El ejemplo de esto es la FUNCIÓN
    resta.*/

void suma (float a, float b);

float resta (float a, float b);

float division (float a, float b);

float multiplicacion (float a, float b);

float factorial (float a);

#endif // FUNCIONES_H_INCLUDED
