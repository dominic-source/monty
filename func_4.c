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

/**
 * sub_mstacklist - subtracts top element from second top
 *
 * @h: the head pointer
 * @ln: line number
 */

void sub_mstacklist(stack_t **h, unsigned int ln)
{
	int sum;

        if (*h == NULL || (*h)->next == NULL)
		ex = 10;
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
	
	if (*h == NULL ||(*h)->next == NULL)
		ex = 11;
	if ((*h)->n == 0)
		ex = 12;
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
	
	if (*h == NULL || (*h)->next == NULL)
		ex = 13;
	*h = (*h)->next;
	mul = (*h)->n * ((*h)->prev)->n;
	(*h)->n = mul;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * mod_mstacklist - modulus of second top element by top
 *
 * @h: the head pointer
 * @ln: line number
 */

void mod_mstacklist(stack_t **h, unsigned int ln)
{
	int mod;
	
	if (*h == NULL || (*h)->next == NULL)
		ex = 14;
	if ((*h)->n == 0)
		ex = 15;
	*h = (*h)->next;
        mod = (*h)->n % ((*h)->prev)->n;
	(*h)->n = mod;
	free((*h)->prev);
	(*h)->prev = NULL;
}
