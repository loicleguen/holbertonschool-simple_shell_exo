#include <stdio.h>
#include <string.h>
#include <unistd.h> /* for environ */

extern char **environ;

/**
 * _getenv - retrieves the value of an environment variable
 * @name: name of the variable (e.g. "PATH")
 *
 * Return: pointer to the value string, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{
		/* Check if this entry starts with name and is followed by '=' */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1); /* skip "NAME=" */
		}
		i++;
	}
	return (NULL);
}

/**
 * main - Entry point of the program
 * Return: Always 0.
 */
int main(void)
{
	char *value;

	value = _getenv("PATH");
	if (value)
		printf("PATH = %s\n", value);
	else
		printf("PATH not found\n");

	value = _getenv("HOME");
	if (value)
		printf("HOME = %s\n", value);
	else
		printf("HOME not found\n");
	return (0);
}
