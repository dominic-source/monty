#include "monty.h"


/**
 * main - interprete monty
 * @argv: arguments
 * @argc: argument counts
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	char *fname, *opcode = NULL;
	unsigned int lnum = 0;
	ssize_t line = 0;
	FILE *file;
	stack_t *head;

	head = NULL;
	ex = 0;
	if (argc != 2)
	{
		error(1, lnum, NULL);
		exit(EXIT_FAILURE);
	}
	fname = argv[1];
	file  = fopen(fname, "r");
	if (file == NULL)
	{
		error(2, lnum, fname);
		free_stackint(&head, lnum);
		exit(EXIT_FAILURE);
	}
	while (line != -1)
	{
		lnum++;
		ex = instruction(lnum, file, &line, &opcode, &head);
		if (ex != 0)
		{
			error(ex, lnum, opcode);
			if (head != NULL)
				free_stackint(&head, lnum);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	if (head != NULL)
		free_stackint(&head, lnum);
	return (0);
}

/**
 * instruction - push an element to the stack
 * @ln: line number
 * @fl: file
 * @l: getline rturn value
 * @opc: opcode to interprete
 * @h: head of nodes
 * Return: 0 or  error number
 */
int instruction(unsigned int ln, FILE *fl, ssize_t *l, char **opc, stack_t **h)
{
	char *lptr;
	stack_t *current;
	instruction_t instruct;
	size_t n;
	int data = 0;

	*l = getline(&lptr, &n, fl);
	if (*l == -1)
		exit(EXIT_SUCCESS);
	ex = find_func(&lptr, &instruct, &data);
	*opc = instruct.opcode;
	if (ex != 0)
		return (ex);
	if (instruct.opcode != NULL && strcmp(instruct.opcode, "") != 0)
	{
		if (instruct.f == NULL)
			return (3);
		instruct.f(h, ln);
		if (strcmp(instruct.opcode, "push") == 0)
		{
			current = *h;
			current->n = data;
		}
	}
	return (ex);
}

/**
 * find_func - handle push
 * @lptr: command
 * @instruct: the opcode and function
 * @data: the data for push if there is
 * Return: 0 or error number if error
 */
int find_func(char **lptr, instruction_t *instruct, int *data)
{
	char *token;
	int flag = 0, i;

	instruction_t arr[] = {
		{"push", add_mstackint}, {"pall", print_mstacklist},
		{"pint", print_end_mstacklist}, {"pop", pop_end_mstacklist},
		{"swap", swap_mstacklist}, {"add", add_mstacklist},
		{"nop", nop_mstacklist}, {"sub", sub_mstacklist},
		{"div", div_mstacklist}, {"mul", mul_mstacklist},
		{"mod", mod_mstacklist},
		{NULL, NULL},
	};
	instruct->opcode = strtok(*lptr, " ");
	token = strtok(NULL, " ");
	if (token != NULL && strcmp(instruct->opcode, "push") == 0)
	{
		for (i = 0; token[i] != '\0' && token[i] != '\n'; i++)
			if (isdigit(token[i]) == 0)
			{
				if (i == 0 && token[i] == '-')
					i = 0;
				else
					return (5);
			}
		*data = atoi(token);
	}
	else if (token == NULL && strcmp(instruct->opcode, "push") == 0)
		return (5);
	instruct->opcode = rm_nwl(instruct->opcode);
	for (i = 0; arr[i].opcode != NULL; i++)
		if (strcmp(arr[i].opcode, instruct->opcode) == 0)
		{
			flag = 1;
			instruct->f = arr[i].f;
			break;
		}
	if (!flag)
		instruct->f = NULL;
	return (0);
}

/**
 * rm_nwl - removes new line character in a string
 * @str: input string
 *
 * Return: string without newline character
 */
char *rm_nwl(char *str)
{
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
	}
	return (str);
}
