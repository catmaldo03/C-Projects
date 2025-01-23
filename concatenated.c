#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char cadena1[100], cadena2[100];
    printf("Ingrese la primera cadena:");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena:");
    scanf("%s", cadena2);
    char *cadena3 = (char *)malloc(strlen(cadena1) + strlen(cadena2) + 1);
    for (int i = 0; i < strlen(cadena1); i++)
    {
        cadena3[i] = cadena1[i];
    }
    cadena3[strlen(cadena1)] = ' ';
    for (int i = 0; i < strlen(cadena2); i++)
    {
        cadena3[strlen(cadena1) + 1 + i] = cadena2[i];
    }
    cadena3[strlen(cadena1) + strlen(cadena2) + 1] = '\0';
    printf("La cadena concatenada es: %s\n", cadena3);
    free(cadena3);
    return 0;
}