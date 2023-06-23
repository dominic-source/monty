#include "monty.h"

/**
 * print_mstacklist - print out the doubly link list
 * @h: the head
 * @ln: line number
 */
void print_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *current;
	unsigned int i;

	current = *h;
	for (i = 0; current != NULL; i++)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
	if (i > ln)
		return;
}

/**
 * add_mstackint - add node at the beginning
 * @head: head of the linked list
 * @n: line number
 *
 */
void add_mstackint(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL && n)
		ex = 4;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
}

/**
 * free_stackint - free linked list
 * @head: the head of the list
 */
void free_stackint(stack_t **head)
{
	stack_t *current = *head;
	unsigned int i;

	for (i = 0; *head != NULL; i++)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}
