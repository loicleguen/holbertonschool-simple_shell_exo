#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Simple shell
 *
 * Return: Always 0.
 */

int main(void)
{	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;

	while (1)
	{	printf("#cisfun$ ");
		fflush(stdout);
		nread = getline(&line, &len, stdin);

		if (nread == -1) /* EOF ou erreur */
		{	printf("\n");
			break;
		}
		/* Retirer le '\n' final de la commande */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{	perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0) /* Code enfant */
		{	char *argv[] = {line, NULL}; /* full path sans argument */

			execve(argv[0], argv, NULL);
			perror("execve"); /* S’exécute seulement si execve échoue */
			_exit(EXIT_FAILURE);
		}
		else /* Code père */
		{
			if (wait(&status) == -1)
				perror("wait");
		}
	}

	free(line);
	return (0);
}
