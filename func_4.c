#include <monty.h>

/**
 * add_mstacklist - adds the top two elements
 *
 * @h: the head pointer
 * @ln: line number
 */

void add_mstacklist(stack_t **h, unsigned int ln)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	*h = (*h)->next;
	sum = (*h)->n + ((*h)->prev)->n;
	(*h)->n = sum;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * nop_mstacklist - does nothing
 *
 * @h: the head pointer
 * @ln: line number
 */

void nop_mstacklist(stack_t **h, unsigned int ln)
{
	void(*h);
	void(ln);
}
