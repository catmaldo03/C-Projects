#include <stdio.h>
#include <stdbool.h>
void analize_text(FILE *text);
int main()
{
    printf("Ingrese el nombre de un archivo para analizar: ");
    char filename[100];
    scanf("%s", filename);
    FILE *text = fopen(filename, "r");
    if (text == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    analize_text(text);
    fclose(text);
    return 0;
}
void analize_text(FILE *text)
{
    int line = 0, characters = 0, words = 0;
    char caracter;
    bool inside_word = false;
    while ((caracter = fgetc(text)) != EOF)
    {
        if (caracter == '\n')
        {
            line++;
            characters--;
        }
        if (caracter == ' ' || caracter == '\t' || caracter == '\n')
        {
            if (inside_word)
            {
                words++;
                characters--;
                inside_word = false;
            }
        }
        else
            inside_word = true;
        characters++;
    }
    if (inside_word)
        words++;

    printf("\nLineas: %d\nPalabras: %d\nCaracteres: %d\n", line, words, characters);
}