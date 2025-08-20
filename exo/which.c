#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  /* for access() */
#include <sys/stat.h>

/**
 * find_in_path - Search for a file in the directories listed in PATH
 * @filename: The name of the file to search for
 *
 * Return: 0 if the file is found and executable, 1 otherwise
 */
int find_in_path(const char *filename)
{
	char *path_env = getenv("PATH");

	if (!path_env)
	{
		fprintf(stderr, "Error: PATH variable not set.\n");
		return (1);
	}
	char *path_copy = strdup(path_env);

	if (!path_copy)
	{
		perror("strdup");
		return (1);
	}
	char *dir = strtok(path_copy, ":");

	while (dir)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
		if (access(full_path, X_OK) == 0)
		{ /* Found executable */
			printf("%s\n", full_path);
			free(path_copy);
			return (0);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (1);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
		return (1);
	}
	int exit_code = 0;

	for (int i = 1; i < argc; i++)
	{
		if (find_in_path(argv[i]) != 0)
		{
			fprintf(stderr, "%s: not found in PATH\n", argv[i]);
			exit_code = 1;
		}
	}
	return (exit_code);
}
