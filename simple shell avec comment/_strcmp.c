1 #include "shell.h"
  2
  3 /**
  4  * _strcmp - Compare deux chaînes de caractères
  5  *         - Compares two strings
  6  * @s1: Première chaîne à comparer
  7  *    - First string to compare
  8  * @s2: Deuxième chaîne à comparer
  9  *    - Second string to compare
 10  *
 11  * Return: Une valeur négative, zéro ou positive selon la comparaison
 12  *       - Negative, zero, or positive value depending on comparison
 13  */
 14 int _strcmp(char *s1, char *s2)
 15 {
 16     /* Parcourt les deux chaînes caractère par caractère */
 17     /* Iterates through both strings character by character */
 18     while (*s1 && (*s1 == *s2))
 19     {
 20         s1++;
 21         s2++;
 22     }
 23
 24     /**
 25      * Retourne la différence entre les caractères non identiques
 26      * Returns the difference between the first non-matching characters
 27      */
 28     return (*s1 - *s2);
 29 }
 30