#include <unistd.h>  // for environ
#include <stdio.h>   // for printf

extern char **environ; // declaration of the global variable

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("Address of env:     %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);
	return (0);
}
