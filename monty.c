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
		free_stackint(&head);
		exit(EXIT_FAILURE);
	}
	while (line != -1)
	{
		lnum++;
		ex = instruction(lnum, file, &line, &opcode, &head);
		if (ex != 0 && ex != -1)
		{
			error(ex, lnum, opcode);
			free(opcode);
			free_stackint(&head);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		free(opcode);
		opcode = NULL;
	}
	free_stackint(&head);
	fclose(file);
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
	char *lptr = NULL;
	instruction_t instruct;
	size_t n = 0;
	int data = 0;

	instruct.opcode = NULL;
	instruct.f = NULL;
	*l = getline(&lptr, &n, fl);
	if (*l == -1)
	{
		free(lptr);
		return (0);
	}
	ex = find_func(&lptr, &instruct, &data);
	if (ex != 0)
	{
		free(lptr);
		return (ex);
	}
	*opc = malloc(sizeof(char) * (strlen(instruct.opcode) + 1));
	if (*opc == NULL)
	{
		free(lptr);
		return (4);
	}
	strcpy(*opc, instruct.opcode);

	if (instruct.opcode != NULL && strcmp(instruct.opcode, "") != 0)
	{
		if (instruct.f == NULL)
		{
			free(lptr);
			return (3);
		}
		instruct.f(h, ln);
		if (strcmp(instruct.opcode, "push") == 0)
			(*h)->n = data;
	}
	free(lptr);
	return (ex);
}

#define IARRAY\
		{\
			{"push", add_mstackint}, {"pall", print_mstacklist},\
			{"pint", print_end_mstacklist},\
			{"pop", pop_end_mstacklist}, {"rotl", rotl_mstacklist},\
			{"swap", swap_mstacklist}, {"add", add_mstacklist},\
			{"nop", nop_mstacklist}, {"sub", sub_mstacklist},\
			{"div", div_mstacklist}, {"mul", mul_mstacklist},\
			{"mod", mod_mstacklist}, {"pchar", pchar_mstacklist},\
			{"pstr", pstr_mstacklist}, {"rotr", rotr_mstacklist},\
			{NULL, NULL},	\
		} \

/**
 * find_func - handle push
 * @lptr: command
 * @instruct: the opcode and function
 * @data: the data for push if there is
 * Return: 0 or error number if error
 */
int find_func(char **lptr, instruction_t *instruct, int *data)
{
	char *token = NULL;
	int flag = 0, i;
	instruction_t arr[] = IARRAY;

	*lptr = rm_nwl(*lptr);
	instruct->opcode = strtok(*lptr, " ");
	if (instruct->opcode == NULL)
		return (-1);
	else if (strncmp(instruct->opcode, "#", 1) == 0)
		return (-1);
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
