#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list node
 * @dir: directory string
 * @next: pointer to the next node
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: pointer to the head pointer
 * @dir: directory string to store
 *
 * Return: pointer to the new node, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *temp;

	if (!new_node)
		return (NULL);
	new_node->dir = strdup(dir);
	if (!new_node->dir)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (new_node);
}

/**
 * build_path_list - builds a linked list of PATH directories
 *
 * Return: pointer to the head of the list, or NULL on failure
 */
list_t *build_path_list(void)
{
	char *path_value = getenv("PATH");

	if (!path_value)
		return (NULL);
	char *path_copy = strdup(path_value);

	if (!path_copy)
		return (NULL);

	list_t *head = NULL;
	char *dir = strtok(path_copy, ":");

	while (dir)
	{
		if (!add_node_end(&head, dir))
		{
			/* Free already allocated nodes in case of failure */
			list_t *tmp;

			while (head)
			{
				tmp = head;
				head = head->next;
				free(tmp->dir);
				free(tmp);
			}
			free(path_copy);
			return (NULL);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

/**
 * free_list - frees a linked list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}

/**
 * main - test the build_path_list function
 * Return: 0 on success
 */
int main(void)
{
	list_t *path_list = build_path_list();
	list_t *temp = path_list;

	while (temp)
	{
		printf("%s\n", temp->dir);
		temp = temp->next;
	}
	free_list(path_list);
	return (0);
}
