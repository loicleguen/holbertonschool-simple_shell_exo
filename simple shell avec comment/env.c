1 #include "shell.h"
  2
  3 /**
  4  * builtin_env - Affiche les variables d'environnement actuelles
  5  *             - Prints the current environment variables
  6  *
  7  * Cette fonction parcourt le tableau global 'environ' et affiche chaque
  8  * variable d'environnement sur une nouvelle ligne.
  9  *
 10  * This function loops through the global 'environ' array and prints each
 11  * environment variable on a new line.
 12  */
 13 void builtin_env(void)
 14 {
 15     int i = 0;
 16
 17     /* Parcourt chaque variable jusqu'à NULL */
 18     /* Loops through each variable until NULL */
 19     while (environ[i] != NULL)
 20     {
 21         /* Affiche la variable d'environnement courante */
 22         /* Prints the current environment variable */
 23         printf("%s\n", environ[i]);
 24         i++;
 25     }
 26 }
 27