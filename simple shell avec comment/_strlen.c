  1 #include "shell.h"
  2
  3 /**
  4  * _strlen - Calcule la longueur d'une chaîne de caractères
  5  *         - Calculates the length of a string
  6  * @s: Chaîne dont on veut connaître la longueur
  7  *   - String whose length is to be determined
  8  *
  9  * Return: Longueur de la chaîne (nombre de caractères avant '\0')
 10  *       - Length of the string (number of characters before '\0')
 11  */
 12 int _strlen(char *s)
 13 {
 14     int len = 0;
 15
 16     /* Parcourt la chaîne jusqu'au caractère nul */
 17     /* Iterates through the string until the null terminator */
 18     while (s[len] != '\0')
 19     {
 20         len++;
 21     }
 22
 23     /* Retourne la longueur calculée */
 24     /* Returns the computed length */
 25     return (len);
 26 }
 27