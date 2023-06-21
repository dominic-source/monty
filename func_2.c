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
