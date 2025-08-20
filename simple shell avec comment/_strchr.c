_strchr.c
  1 #include "shell.h"
  2
  3 /**
  4  * _strchr - Recherche un caractère dans une chaîne de caractères
  5  *         - Locates a character in a string
  6  * @str: Chaîne dans laquelle chercher
  7  *     - The string to search
  8  * @c: Caractère à trouver
  9  *   - The character to find
 10  *
 11  * Return: Pointeur vers la première occurrence de c dans str, ou NULL si absent
 12  *       - Pointer to the first occurrence of c in str, or NULL if not found
 13  */
 14 char *_strchr(const char *str, int c)
 15 {
 16     /* Parcourt la chaîne jusqu'à la fin */
 17     /* Iterates through the string until the end */
 18     while (*str)
 19     {
 20         /* Vérifie si le caractère courant correspond à c */
 21         /* Checks if the current character matches c */
 22         if (*str == (char)c)
 23             return ((char *)str);
 24         str++;
 25     }
 26
 27     /**
 28      * Si c est le caractère nul '\0', retourne un pointeur vers le terminateur
 29      * If c is the null character '\0', return a pointer to the terminator
 30      */
 31     if (c == '\0')
 32         return ((char *)str);
 33
 34     /* Retourne NULL si le caractère n'est pas trouvé */
 35     /* Returns NULL if the character is not found */
 36     return (NULL);
 37 }
 38