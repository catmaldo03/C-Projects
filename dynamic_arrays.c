#include <stdio.h>
#include <stdlib.h>
int *create_array(int n);
void fill_array(int *array, int n);
void add_array(int **array, int *n);
void search_array(int *array, int n);
void delete_array(int **array, int *n);
int main()
{
    int choice;
    printf("Hi, do you want to create an array of integers? If yes, select 1, if not select 0\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("How many elements do you want in the array?\n");
        int n;
        scanf("%d", &n);
        int *array = create_array(n);
        printf("Array created successfully\n");
        fill_array(array, n);

        do
        {
            printf("What do you want to do next?\n");
            printf("1. Show the array\n");
            printf("2. Add more numbers\n");
            printf("3. search for a number\n");
            printf("4. delete a number\n");
            printf("5. exit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", array[i]);
                }
                break;
            case 2:
                add_array(&array, &n);
                break;
            case 3:
                search_array(array, n);
                break;
            case 4:
                delete_array(&array, &n);
                break;
            case 5:
                printf("Okay, have a nice day!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        } while (choice != 5);
        free(array);
    }
    else if (choice == 0)
    {
        printf("Okay, have a nice day!\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}
int *create_array(int n)
{
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return array;
}
void fill_array(int *array, int n)
{
    int choice;
    printf("How do you want to fill the array?\n");
    printf("1. Fill the array with random numbers\n");
    printf("2. Fill the array with user input\n");
    printf("3. ones");
    printf("4. zeros");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            array[i] = rand() % 100;
        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d: ", i);
            scanf("%d", &array[i]);
        }
        break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            array[i] = 1;
        }
        break;
    case 4:
        for (int i = 0; i < n; i++)
        {
            array[i] = 0;
        }
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    printf("Array filled successfully\n");
}
void add_array(int **array, int *n)
{
    int m;

    printf("How many elements do you want to add?\n");
    scanf("%d", &m);
    int *new_array = (int *)realloc(*array, (*n + m) * sizeof(int));
    if (new_array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    *array = new_array;
    for (int i = *n; i < *n + m; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &(*array)[i]);
    }
    printf("Elements added successfully\n");
    *n += m;
}
void search_array(int *array, int n)
{
    int num, flag = 0;
    printf("Enter the number you want to search for: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        if (array[i] == num)
        {
            printf("Number found at index %d\n", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Number not found\n");
    }
}
void delete_array(int **array, int *n)
{
    int num, flag = 0;
    printf("Enter the number you want to delete: ");
    scanf("%d", &num);
    for (int i = 0; i < *n; i++)
    {
        if ((*array)[i] == num)
        {
            for (int j = i; j < *n - 1; j++)
            {
                (*array)[j] = (*array)[j + 1];
            }
            flag = 1;
            (*n)--;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Number not found\n");
    }
    else
    {
        *array = (int *)realloc(*array, *n * sizeof(int));
        printf("Number deleted successfully\n");
    }
}