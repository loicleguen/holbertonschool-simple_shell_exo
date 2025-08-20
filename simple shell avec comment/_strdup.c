1 #include "shell.h"
  2
  3 /**
  4  * _strdup - Duplique une chaîne de caractères en mémoire dynamique
  5  *         - Duplicates a string into newly allocated memory
  6  * @str: Chaîne à dupliquer
  7  *     - String to duplicate
  8  *
  9  * Return: Pointeur vers la copie de la chaîne, ou NULL si échec mémoire
 10  *       - Pointer to the duplicated string, or NULL if memory allocation fails
 11  */
 12 char *_strdup(char *str)
 13 {
 14     char *copy;
 15     int i, len = 0;
 16
 17     /* Vérifie si la chaîne source est NULL */
 18     /* Checks if the source string is NULL */
 19     if (str == NULL)
 20     {
 21         return (NULL);
 22     }
 23
 24     /* Calcule la longueur de la chaîne source */
 25     /* Calculates the length of the source string */
 26     while (str[len])
 27     {
 28         len++;
 29     }
 30
 31     /* Alloue de la mémoire pour la copie (+1 pour le '\0') */
 32     /* Allocates memory for the copy (+1 for the '\0') */
 33     copy = malloc(sizeof(char) * (len + 1));
 34     if (copy == NULL)
 35     {
 36         return (NULL);
 37     }
 38
 39     /* Copie chaque caractère de la chaîne source */
 40     /* Copies each character from the source string */
 41     for (i = 0; i < len; i++)
 42     {
 43         copy[i] = str[i];
 44     }
 45
 46     /* Termine la nouvelle chaîne par le caractère nul */
 47     /* Terminates the new string with the null character */
 48     copy[len] = '\0';
 49
 50     return (copy);
 51 }
 52