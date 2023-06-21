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
 * get_opcode - retrieves opcode from monty file
 *
 * @opcode: pointer to opcode function
 * @data: opcode value
 * @FILE: file stream to read line from
 *
 * Return: 0 if successful and -1 if not
 */

void get_opcode(char **opcode, int *data, FILE *file)
{
	char **lptr;
	size_t n;
	char *dat;

	*lptr = NULL;
	n = 0;
	getline(lptr, &n, file);
	opcode[0] = strtok(lptr, " ");
	dat = strtok(NULL, " ");
	*data = atoi(dat);

	return;
}
