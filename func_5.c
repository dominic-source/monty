#include "monty.h"


/**
 * pstr_mstacklist - print the string starting at the top of the stack
 *
 * @h: the head of the stack
 * @ln: line number
 */
void pstr_mstacklist(stack_t **h, unsigned int ln)
{
	stack_t *current = *h;
	int i;

	ln = ln;
	for (i = 0; current != NULL; i++)
	{
		if (current->n > 32 && current->n < 128)
			printf("%c", ((char)current->n));
		else if (current->n == 0)
			break;
		else
			break;
		current = current->next;
	}
	printf("\n");
}


/**
 * rotr_mstacklist - rotate the stack to the bottom
 *
 * @h: the head of the stack
 * @ln: line number
 */
void rotr_mstacklist(stack_t **h, unsigned int ln)
{
	h = h;
	ln = ln;

}
