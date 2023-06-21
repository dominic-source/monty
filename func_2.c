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

int get_opcode(char **opcode, int *data, FILE *file)
{
	char *lptr;
	size_t n;
	char *dat;
	char *token;
	ssize_t line;

	lptr = NULL;
	n = 0;
	line = getline(&lptr, &n, file);
	token = strtok(lptr, " ");
	*opcode = malloc(sizeof(char) * (strlen(token) + 1));
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = &token;
	dat = strtok(NULL, " ");
	if (dat != NULL)
		*data = atoi(dat);
	free(lptr);

	return (line);
}
