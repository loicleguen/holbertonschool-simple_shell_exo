  1 #ifndef SHELL_H
  2 #define SHELL_H
  3
  4 #include <stdlib.h>
  5 #include <unistd.h>
  6 #include <sys/wait.h>
  7 #include <string.h>
  8 #include <errno.h>
  9 #include <stdio.h>
 10
 11 /*
 12  * PROMPT - Définition du texte affiché comme invite de commande
 13  *        - Defines the shell prompt displayed to the user
 14  */
 15 #define PROMPT "#LFG$ "
 16
 17 /*
 18  * environ - Variable globale contenant l'environnement du programme
 19  *         - Global variable containing the program's environment
 20  */
 21 extern char **environ;
 22
 23 /**
 24  * struct command_s - Structure représentant une commande avec ses arguments
 25  *                  - Structure representing a command with its arguments
 26  * @line: Ligne brute saisie par l'utilisateur
 27  *      - Raw command line entered by the user
 28  * @args: Tableau d'arguments, incluant le nom de la commande, terminé par NULL
 29  *      - Array of arguments including command name, NULL-terminated
 30  */
 31 typedef struct command_s
 32 {
 33     char *line;   /* Ligne de commande saisie par l'utilisateur */
 34     char **args;  /* Arguments de la commande */
 35 } command_t;
 36 /**
 38  * read_command - Lit une ligne de commande depuis l'entrée standard
 39  *              - Reads a command line from standard input
 40  * @input: Pointeur vers la ligne lue
 41  *       - Pointer to the read line
 42  * @bufsize: Taille du tampon de lecture
 43  *         - Size of the input buffer
 44  * @is_interactive: Mode interactif ou non
 45  *                - Whether the shell is in interactive mode
 46  * Return: Nombre d'octets lus ou -1 en cas d'erreur
 47  *       - Number of bytes read or -1 on error
 48  */
 49 ssize_t read_command(char **input, size_t *bufsize, int is_interactive);
 50
 51 /**
 52  * parse_command - Analyse la ligne de commande en arguments
 53  *               - Parses the command line into arguments
 54  * @line: Ligne brute à analyser
 55  *      - Raw input line to parse
 56  * Return: Tableau d'arguments terminé par NULL
 57  *       - Array of arguments ending with NULL
 58  */
 59 char **parse_command(char *line);
 60
 61 /**
 62  * execute_command - Exécute une commande donnée
 63  *                 - Executes a given command
 64  * @cmd: Structure contenant la commande et ses arguments
 65  *     - Structure containing the command and its arguments
 66  * Return: Code de retour du processus enfant
 67  *       - Return code from the child process
 68  */
 69 int execute_command(command_t cmd);
 70
 71 /**
 72  * find_command_in_path - Recherche le chemin absolu d'une commande
 73  *                       - Finds the absolute path of a command
 74  * @command: Nom de la commande à rechercher
 75  *         - Name of the command to search
 76  * Return: Chemin complet ou NULL si introuvable
 77  *       - Full path or NULL if not found
 78  */
 char *find_command_in_path(char *command);
 80
 81 /**
 82  * _strdup - Duplique une chaîne de caractères
 83  *         - Duplicates a string
 84  * @str: Chaîne à dupliquer
 85  *     - String to duplicate
 86  * Return: Pointeur vers la nouvelle chaîne ou NULL
 87  *       - Pointer to new string or NULL
 88  */
 89 char *_strdup(char *str);
 90
 91 /**
 92  * _strlen - Calcule la longueur d'une chaîne
 93  *         - Calculates the length of a string
 94  * @s: Chaîne de caractères
 95  *   - Input string
 96  * Return: Longueur de la chaîne
 97  *       - Length of the string
 98  */
 99 int _strlen(char *s);
100
101 /**
102  * _strcmp - Compare deux chaînes de caractères
103  *         - Compares two strings
104  * @s1: Première chaîne
105  *    - First string
106  * @s2: Deuxième chaîne
107  *    - Second string
108  * Return: Résultat de la comparaison
109  *       - Result of comparison
110  */
111 int _strcmp(char *s1, char *s2);
112
113 /**
114  * _getenv - Récupère la valeur d'une variable d'environnement
115  *         - Retrieves the value of an environment variable
116  * @name: Nom de la variable
117  *      - Name of the variable
118  * Return: Valeur de la variable ou NULL
119  *       - Value of the variable or NULL
120  */
121 char *_getenv(const char *name)
123 /**
124  * _strchr - Recherche un caractère dans une chaîne
125  *         - Searches for a character in a string
126  * @str: Chaîne source
127  *     - Source string
128  * @c: Caractère à rechercher
129  *    - Character to find
130  * Return: Pointeur vers le caractère ou NULL
131  *       - Pointer to character or NULL
132  */
133 char *_strchr(const char *str, int c);
134
135 /**
136  * builtin_env - Affiche les variables d'environnement
137  *             - Displays environment variables
138  */
139 void builtin_env(void);
140
141 /**
142  * main - Point d'entrée du programme shell
143  *      - Entry point of the shell program
144  * Return: 0 en cas de succès
145  *       - 0 on success
146  */
147 int main(void);
148
149 #endif /* SHELL_H */
