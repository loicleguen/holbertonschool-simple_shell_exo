#include <stdio.h>


/**
 * main - Entry point
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	while (av[i] != NULL)
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
    return (0);
}
