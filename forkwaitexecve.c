#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork, wait and execve example
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (int i = 0; i < 5; i++) /* 5 enfants, créés un par un */
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}

		if (child_pid == 0) /* Code exécuté par l’enfant */
		{
			execv(argv[0], argv);
			perror("execv"); /* S’exécute seulement si execv échoue */
			_exit(1);
		}

		/* Code du père : attendre la fin de l’enfant */
		if (wait(&status) == -1)
		{
			perror("wait");
			return (1);
		}

		if (WIFEXITED(status))
		{
			printf("Child %d exited with status %d\n",
				   child_pid, WEXITSTATUS(status));
		}
		else
		{
			printf("Child %d exited abnormally\n", child_pid);
		}
	sleep(1);
	}
	return (0);
}
