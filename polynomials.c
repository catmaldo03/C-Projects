#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *sum_polynomials(int *first_poly, int *second_poly, int degree);
void evaluate_polynomial(int *sum_poly, int degree);
int main()
{
    int degree = 2;
    int *first_poly = (int *)malloc((degree + 1) * sizeof(int));
    int *second_poly = (int *)malloc((degree + 1) * sizeof(int));
    for (int i = 0; i <= degree; i++)
    {
        first_poly[i] = rand() % 10;
        second_poly[i] = rand() % 10;
    }
    printf("\nThe first polynomial is: \n");
    for (int i = 0; i <= degree; i++)
    {
        printf("%dx^%d ", first_poly[i], degree - i);
        if ((degree - i) != 0)
        {
            printf("+ ");
        }
    }
    printf("\nThe second polynomial is: \n");
    for (int i = 0; i <= degree; i++)
    {
        printf("%dx^%d ", second_poly[i], degree - i);
        if ((degree - i) != 0)
        {
            printf("+ ");
        }
    }
    int *sum_poly = sum_polynomials(first_poly, second_poly, degree);
    printf("\nThe sum of the two polynomials is: \n");
    for (int i = 0; i <= degree; i++)
    {
        printf("%dx^%d ", sum_poly[i], degree - i);
        if ((degree - i) != 0)
        {
            printf("+ ");
        }
    }
    evaluate_polynomial(sum_poly, degree);
    free(first_poly);
    free(second_poly);
    free(sum_poly);
    return 0;
}
int *sum_polynomials(int *first_poly, int *second_poly, int degree)
{
    int *sum_poly = (int *)malloc((degree + 1) * sizeof(int));
    for (int i = 0; i <= degree; i++)
    {
        sum_poly[i] = first_poly[i] + second_poly[i];
    }
    return sum_poly;
}
void evaluate_polynomial(int *sum_poly, int degree)
{
    int x;
    printf("\nEnter the value of x: ");
    scanf("%d", &x);
    int result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result += sum_poly[i] * pow(x, degree - i);
    }
    printf("The result of the polynomial is %d\n", result);
}
