// declaracion de las librerias
#include <stdio.h>
#include <stdbool.h>
int main()
{
    // declaracion de las variables
    int n = 0;
    int i, j = 0;
    // mensajes que indican la funcion del programa, y le pide al usuario ingresar el numero maximo del rango
    printf("Hola, este es un programa que indica la cantidad de numeros primos en un rango determinado de numeros\n");
    printf("Ingrese el maximo del rango que parte del 1: ");
    scanf("%d", &n);
    printf("\n");
    // creacion del arreglo booleano que servira para indicar que numeros son primos y cuales no
    bool primos[n];
    // se marcan todos los numeros como primos
    for (i = 0; i < n; i++)
    {
        primos[i] = true;
    }
    // se quitan el 0 y 1 como numeros primos
    primos[0] = primos[1] = false;
    if (n > 2)
    {
        for (i = 2; i * i <= n; i++)
        {
            // si primos en i es verdadero
            if (primos[i])
            {
                // se marcan los multiplos de i como no primos, vease la primera ves j = 4 ( 2 x 2), sigue hasta que j sea menos o igual a n, y j aumenta de 2 en 2, indica que toda la secuencia de numeros no son primos
                for (j = i * i; j <= n; j += i)
                {
                    primos[j] = false;
                }
            }
        }
        // una vez completado el recorrido, se imprime los numeros que siguen marcado como TRUE, que serian los numeros primos
        for (i = 2; i <= n; i++)
        {
            if (primos[i])
            {
                printf("%d  ", i);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Numero no valido\n");
    }
    return 0;
}