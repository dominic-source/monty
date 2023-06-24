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

	If (*h == NULL)
	{
		error(6, ln, "pchar");
		return;
	}
	pchar = (*h)->n;
	if (pchar < 0 || pchar > 127)
	{
		error(10, ln);
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
	stack_t buffer;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	buffer = *h;
	ln = ln;
	while (buffer->next != NULL)
	{
		buffer = buffer->next;
	}
	buffer->next = *h;
	(*h)->next = NULL;
	(*h)->prev = buffer;
	*h = (*h)->next;
	(*h)->prev = NULL;
}
