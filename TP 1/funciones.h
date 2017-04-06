#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/**
*Aclaraci�n general:
    Dado que las funciones, luego de calcular, imprimen el resultado, no es necesario que devuelvan nada. As� se ejemplifica
    en la FUNCI�N suma. Sin embargo, opt� por programar las dem�s funciones de forma tal que devulvan el resultado
    de la operaci�n, en caso de que quisieran usarse para otros fines (adem�s de la simple impresi�n del resultado). En ese
    caso, se borrar�a la l�nea de impresi�n (printf) en la funci�n, y se asignar�a en el main a una variable nuestra funci�n.
    Podr�amos as� imprimir �sta variable o relacionarla con cualquier otra que quisieramos. El ejemplo de esto es la FUNCI�N
    resta.*/

void suma (float a, float b);

float resta (float a, float b);

float division (float a, float b);

float multiplicacion (float a, float b);

float factorial (float a);

#endif // FUNCIONES_H_INCLUDED
