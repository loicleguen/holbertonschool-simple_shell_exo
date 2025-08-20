#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path_dirs - prints each directory from PATH on a separate line
 */
void print_path_dirs(void)
{
	char *path_value = getenv("PATH");

	if (!path_value)
	{
		printf("PATH not found\n");
		return;
	}
	/* Duplicate string because strtok modifies it */
	char *path_copy = strdup(path_value);

	if (!path_copy)
	{
		perror("strdup");
		return;
	}
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}

/**
 * main - Entry point of the program
 * Return: Always 0.
 */
int main(void)
{
	print_path_dirs();
	return (0);
}
