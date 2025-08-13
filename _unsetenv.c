#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _unsetenv - Remove an environment variable
 * @name: variable name (must not contain '=')
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	int i, j;
	size_t len;

	if (name == NULL || strchr(name, '=') != NULL || *name == '\0')
		return (-1);
	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/* Décaler toutes les entrées suivantes */
			for (j = i; environ[j] != NULL; j++)
				environ[j] = environ[j + 1];
			i--; /* vérifier à nouveau cette position */
		}
	}
	return (0);
}

/**
 * main - Test the _unsetenv function
 *
 * Return: 0 on success
 */
int main(void)
{
	setenv("TEST", "Hello", 1);
	printf("Before unset: %s\n", getenv("TEST"));
	unsetenv("TEST");
	printf("After unset: %s\n", getenv("TEST"));
	return (0);
}
