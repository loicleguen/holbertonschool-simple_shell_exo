#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	if (nread == -1)
	{
		printf("EOF\n");
	}
	free(line);
	return 0;
}
