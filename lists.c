#include "shell.h"

/**
 * add_node - adds node to list at beginning
 * @head: pointer head node
 * @str: string of node
 * @num: node
 * Return: @n_head, new head of node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *n_head;

	if (!head)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = num;
	if (str)
	{
		n_head->str = _strdup(str);
		if (!n_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	n_head->next = *head;
	*head = n_head;
	return (n_head);
}

/**
 * add_node_end - adds node to list at the end
 * @head: pointer head node
 * @str: string of node
 * @num: node
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *n_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0, sizeof(list_t));
	n_node->num = num;
	if (str)
	{
		n_node->str = _strdup(str);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*head = n_node;
	return (new_node);
}

/**
 * print_list_str - prints out the ->str for the list passed
 * @j: first node pointer
 * Return: list size
 */
size_t print_list_str(const list_t *j)
{
	size_t a = 0;

	while (j)
	{
		_puts(j->str ? j->str : "(nil)");
		_puts("\n");
		j = j->next;
		a++;
	}
	return (a);
}

/**
 * delete_node_at_index - deletes node @index
 * @head: pointer to first node
 * @index: index node to delete
 * Return: 1 (Success), 0 (Failure)
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int a = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (a == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		a++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees nodes from list
 * @head_ptr: pointer to head node
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
