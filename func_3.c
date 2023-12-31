#include "monty.h"

/**
 * pchar_mstacklist -  prints the char at the top of the stack
 *
 * @h: the head pointer
 * @ln: line number
 */

void pchar_mstacklist(stack_t **h, unsigned int ln)
{
	int pchar;

	if (*h == NULL)
	{
		ex = 6;
		return;
	}
	ln = ln;
	pchar = (*h)->n;
	if (pchar < 0 || pchar > 127)
	{
		ex = 10;
		return;
	}
	printf("%c\n", pchar);
}

/**
 * rotl_mstacklist - rotates the stack to the top
 *
 * @h: the head pointer
 * @ln: line number
 */

void rotl_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *buffer;
	stack_t *current;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	buffer = *h;
	current = *h;
	ln = ln;

	while (buffer->next != NULL)
	{
		buffer = buffer->next;
	}
	buffer->prev = NULL;
	buffer->next = *h;

	*h = (*h)->next;
	current->next = NULL;
	current->prev = buffer;
}
