#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point of the shell prompt program.
 * Reads input from the user, prints it back, and displays a prompt.
 * until EOF (End of File) is encountered.
 *
 * Return: Always 0 on success.
 */

int main(void)
{
	char *line = NULL;   /* pointeur pour la ligne lue */
	size_t len = 0;      /* taille du buffer */
	ssize_t nread;       /* nombre de caractères lus */

	printf("$ ");        /* afficher le prompt */
	fflush(stdout);      /* forcer l'affichage immédiat */

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		printf("%s", line);
		printf("$ ");
		fflush(stdout);
	}
	if (feof(stdin))
		printf("EOF\n");

	free(line);
	return (0);
}
