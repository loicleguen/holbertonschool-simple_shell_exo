#include <stdio.h>
#include <unistd.h>  // for environ

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char **environ; // declaration of the global variable

int main(void)
{
	char **env = environ;

	while (*env)
	{              // loop until NULL pointer
		printf("%s\n", *env);   // print each "NAME=value" string
		env++;
	}
	return (0);
}
