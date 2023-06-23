#include "monty.h"
/**
 * add_mstacklist - adds the top two elements
 *
 * @h: the head pointer
 * @ln: line number
 */

void add_mstacklist(stack_t **h, unsigned int ln)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL || ln == 0)
	{
		ex = 8;
		return;
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
	*h = *h;
	ln = ln;
}

/**
 * sub_mstacklist - subtracts top element from second top
 *
 * @h: the head pointer
 * @ln: line number
 */

void sub_mstacklist(stack_t **h, unsigned int ln)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL || ln == 0)
	{
		ex = 8;
		return;
	}
	*h = (*h)->next;
	sum = (*h)->n - ((*h)->prev)->n;
	(*h)->n = sum;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * div_mstacklist - divides second top element by top
 *
 * @h: the head pointer
 * @ln: line number
 */

void div_mstacklist(stack_t **h, unsigned int ln)
{
	int div;

	if (*h == NULL || (*h)->next == NULL)
	{
		ex = 8;
		return;
	}
	if ((*h)->n == 0 || ln == 0)
	{
		ex = 9;
		return;
	}
	*h = (*h)->next;
	div = (*h)->n / ((*h)->prev)->n;
	(*h)->n = div;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * mul_mstacklist - multiplies second top element by top
 *
 * @h: the head pointer
 * @ln: line number
 */

void mul_mstacklist(stack_t **h, unsigned int ln)
{
	int mul;

	if (*h == NULL || (*h)->next == NULL || ln == 0)
	{
		ex = 8;
		return;
	}
	*h = (*h)->next;
	mul = (*h)->n * ((*h)->prev)->n;
	(*h)->n = mul;
	free((*h)->prev);
	(*h)->prev = NULL;
}
