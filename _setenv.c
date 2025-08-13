#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _setenv - Change or add an environment variable
 * @name: variable name (must not contain '=')
 * @value: variable value
 * @overwrite: 1 to overwrite existing, 0 to keep existing
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len;
	int i;
	char *new_var;

	if (!name || !value || strchr(name, '='))
	{
		fprintf(stderr, "Invalid name or value\n");
		return (-1);
	}
	name_len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{	/* Search if variable already exists */
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			if (!overwrite)
				return (0); /* keep existing value */
			/* Replace existing */
			new_var = malloc(name_len + strlen(value) + 2);
			if (!new_var)
				return (-1);
			sprintf(new_var, "%s=%s", name, value);
			environ[i] = new_var;
			return (0);
		}
	}
	/* Variable does not exist → add it */
	new_var = malloc(name_len + strlen(value) + 2);
	if (!new_var)
		return (-1);
	sprintf(new_var, "%s=%s", name, value);
	char **new_environ = malloc((i + 2) * sizeof(char *));
		/* Extend environ */
	if (!new_environ)
		return (-1);
	for (int j = 0; j < i; j++)
		new_environ[j] = environ[j];
	new_environ[i] = new_var;
	new_environ[i + 1] = NULL;
	environ = new_environ;
	return (0);
}

/**
 * main - test the _setenv function
 *
 * Return: 0 on success
 */
int main(void)
{
	_setenv("MYVAR", "hello", 1);
	printf("MYVAR = %s\n", getenv("MYVAR"));
	_setenv("MYVAR", "world", 0); /* will not overwrite */
	printf("MYVAR = %s\n", getenv("MYVAR"));
	_setenv("MYVAR", "world", 1); /* overwrite */
	printf("MYVAR = %s\n", getenv("MYVAR"));
	return (0);
}
