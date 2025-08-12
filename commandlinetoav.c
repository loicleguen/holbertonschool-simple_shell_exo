#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * resize_av - Resize the argument vector
 * @av: The original argument vector
 * @size: A pointer to the current size of the argument vector
 * Return: A pointer to the resized argument vector, or NULL on failure
 */
char **resize_av(char **av, int *size)
{
	int new_size = (*size) * 2;
	char **tmp = realloc(av, sizeof(char *) * new_size);

	if (!tmp)
		return (NULL);
	*size = new_size;
	return (tmp);
}

/**
 * free_av - Free the argument vector
 * @av: The argument vector to free
 * @count: The number of arguments in the vector
 */
void free_av(char **av, int count)
{
	for (int i = 0; i < count; i++)
		free(av[i]);
	free(av);
}

/**
 * split_line_to_av - Split a line into an argument vector
 * @line: The line to split
 * @out_count: A pointer to an integer to store the number of arguments
 * Return: A pointer to the argument vector, or NULL on failure
 */
char **split_line_to_av(char *line, int *out_count)
{
	int size = 10;
	int count = 0;
	char **av = malloc(sizeof(char *) * size);
	char *token;

	if (!av)
		return (NULL);
	token = strtok(line, " \t\n");
	while (token)
	{
		av[count] = strdup(token);
		if (!av[count])
		{
			free_av(av, count);
			return (NULL);
		}
		count++;
		if (count >= size)
		{
			char **tmp = resize_av(av, &size);

			if (!tmp)
			{
				free_av(av, count);
				return (NULL);
			}
			av = tmp;
		}
		token = strtok(NULL, " \t\n");
	}
	av[count] = NULL;
	*out_count = count;
	return (av);
}

/**
 * command_line_to_av - Convert a command line string to an argument vector
 * @line: The command line string to convert
 * Return: A pointer to the argument vector, or NULL on failure
 */
char **command_line_to_av(char *line)
{
	char *line_copy;
	char **av;
	int count = 0;

	if (!line)
		return (NULL);
	line_copy = strdup(line);
	if (!line_copy)
		return (NULL);
	av = split_line_to_av(line_copy, &count);
	free(line_copy);
	return (av);
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char **av = command_line_to_av("ls -l home/user rghiog\nrgohigf\tdsiohg");
	int i = 0;

	if (!av)
	{
		fprintf(stderr, "Erreur d'allocation\n");
		return (1);
	}
	while (av[i])
	{
		printf("av[%d] = %s\n", i, av[i]);
		i++;
	}
	free_av(av, i);
	return (0);
}
