#include "monty.h"

/**
 * get_mstack_at_index - get the nth node of a linked list
 *
 * @head: pointer head of the list
 * @index: position
 *
 * Return: return the node or NULL if it not exist
 */
stack_t *get_mstack_at_index(stack_t *head, unsigned int index)
{
	stack_t *temp;
	unsigned int num_nodes = 0;

	temp = head;
	while (temp != NULL && num_nodes <= index)
	{
		if (num_nodes == index)
			return (temp);
		temp = temp->next;
		num_nodes++;
	}
	return (NULL);
}

/**
 * error - print appropriate error
 * @n: error number
 * @line: line number
 * @amsg: additional message
 */
void error(int n, unsigned int line, char *amsg)
{
	switch (n)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", amsg);
		break;
	case 3:
		fprintf(stderr, "L%i: unknown instruction %s\n", line, amsg);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%i: usage: push integer\n", line);
		break;
	case 6:
		fprintf(stderr, "L%i: can't pint, stack empty\n", line);
		break;
	case 7:
		fprintf(stderr, "L%i: can't pop an empty stack\n", line);
		break;
	case 8:
		fprintf(stderr, "L%i: can't swap, stack too short", line);
		break;
	default:
		return;
	}
}

/**
 * print_end_mstacklist - prints value at top of the stack
 *
 * @h: the head ponter
 * @ln: line number
 */

void print_end_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *current;

	if (*h == NULL || ln == 0)
	{
		ex = 6;
		return;
	}
	current = *h;
	printf("%d\n", current->n);
}

/**
 * pop_end_mstacklist - removes the top element of the stack
 *
 * @h: the head pointer
 * @ln: line number
 */

void pop_end_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *current;

	if (*h == NULL || h == NULL || ln == 0)
	{
		ex = 7;
		return;
	}
	current = *h;
	*h = (*h)->next;
	if (*h != NULL)
		(*h)->prev = NULL;
	free(current);
}

/**
 * swap_mstacklist - swaps last two elements of the stack
 *
 * @h: the head pointer
 * @ln: line number
 */

void swap_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *current;

	if (*h == NULL || (*h)->next == NULL || ln == 0)
	{
		ex = 8;
		return;
	}
	current = (*h)->next;
	(*h)->next = current->next;
	if (current->next != NULL)
		(current->next)->prev = *h;
	current->next = *h;
	(*h)->prev = current;
	current->prev = NULL;
	*h = current;
}
