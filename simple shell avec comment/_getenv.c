 1 #include "shell.h"
  2
  3 /**
  4  * _getenv - Récupère la valeur d'une variable d'environnement
  5  *         - Retrieves the value of an environment variable
  6  * @name: Nom de la variable (ex: "PATH")
  7  *      - Name of the variable (e.g. "PATH")
  8  *
  9  * Return: Pointeur vers la valeur de la variable, ou NULL si non trouvée
 10  *       - Pointer to the value string, or NULL if not found
 11  */
 12 char *_getenv(const char *name)
 13 {
 14     int i = 0;
 15     size_t len = strlen(name);
 16
 17     /* Parcourt le tableau environ jusqu'à la fin */
 18     /* Iterates through the environ array until the end */
 19     while (environ[i] != NULL)
 20     {
 21         /**
 22          * Vérifie si l'entrée commence par le nom suivi de '='
 23          * Checks if the entry starts with name followed by '='
 24          */
 25         if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
 26         {
 27             /**
 28              * Retourne un pointeur vers la valeur (après "NAME=")
 29              * Returns a pointer to the value (after "NAME=")
 30              */
 31             return (environ[i] + len + 1);
 32         }
 33         i++;
 34     }
 35
 36     /* Retourne NULL si la variable n'est pas trouvée */
 37     /* Returns NULL if the variable is not found */
 38     return (NULL);
 39 }
 40