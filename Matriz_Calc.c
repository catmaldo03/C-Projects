#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Ingrese el tamaño de la  primera matriz:");
    int n, m;
    scanf("%d %d", &n, &m);
    printf("Seleccione, como rellenar la matriz\n 1. manual\n 2. aleatorio \n 3. cero\n 4. uno\n");
    int type;
    scanf("%d", &type);
    int matriz[n][m];
    switch (type)
    {
    case 1:
        printf("Ingrese los valores de la matriz\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }
        break;
    case 2:
        printf("Se va a rellenar la matriz con numeros aleatorios\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz[i][j] = rand() % 100;
            }
        }
        break;
    case 3:
        printf("Se va a rellenar la matriz con ceros\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz[i][j] = 0;
            }
        }
        break;
    case 4:
        printf("Se va a rellenar la matriz con uno\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz[i][j] = 1;
            }
        }
        break;

    default:
        printf("Opcion no valida\n");
        break;
    }
    int matriz2[n][m];
    printf("Seleccione, como rellenar la segunda matriz\n 1. manual\n 2. aleatorio \n 3. cero\n 4. uno\n");
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        printf("Ingrese los valores de la matriz\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &matriz2[i][j]);
            }
        }
        break;
    case 2:
        printf("Se va a rellenar la matriz con numeros aleatorios\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz2[i][j] = rand() % 100;
            }
        }
        break;
    case 3:
        printf("Se va a rellenar la matriz con ceros\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz2[i][j] = 0;
            }
        }
        break;
    case 4:
        printf("Se va a rellenar la matriz con uno\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matriz2[i][j] = 1;
            }
        }
        break;

    default:
        printf("Opcion no valida\n");
        break;
    }
    printf("Seleccione la operacion a realizar\n 1. Suma\n 2. Resta\n 3. Multiplicacion\n");
    int operation;
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        printf("Suma de las matrices\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", matriz[i][j] + matriz2[i][j]);
            }
            printf("\n");
        }
        break;
    case 2:
        printf("Resta de las matrices\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", matriz[i][j] - matriz2[i][j]);
            }
            printf("\n");
        }
        break;
    case 3:
        printf("Multiplicacion de las matrices\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", matriz[i][j] * matriz2[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Opcion no valida \n");
        break;
    }
    return 0;
}