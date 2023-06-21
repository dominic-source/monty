#include "monty.h"


/**
 * main - interprete monty
 * @argv: arguments
 * @argc: argument counts
 * Return: 0 or 1
 */
int main(int argc, char* argv[])
{
	char *fname;
	int lnum = 0;
	ssize_t line = 0;
	FILE *file;
	instruction_t interprete;
	unsigned int count = 0;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fname = argv[1];
	file  = fopen(fname, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while (line != -1)
	{
		lnum++;
		interprete = instruction(lnum, &count, file, &line);
		printf("1---%s---\n", interprete.opcode);
/*		interprete.f();
 */	}
	fclose(file);
	return (0);
}

/**
 * instruction - push an element to the stack
 * @opcode: opcode to interprete
 */
instruction_t instruction(unsigned int lnum, unsigned int *count, FILE *file, ssize_t *l)
{
	char *lptr, *token;
	int data = 0;
	instruction_t instruct;
        size_t n;

	*l = getline(&lptr, &n, file);
	if (*l == -1)
		exit(EXIT_SUCCESS);
        instruct.opcode = strtok(lptr, " ");
        token = strtok(NULL, " ");

	if (token != NULL)
                data = atoi(token);
	instruct.opcode = rm_nwl(instruct.opcode);

	if (strcmp(instruct.opcode, "push") == 0)
	{
		add_mstackint(&head, data);
		(*count)++;
	}
	else if (strcmp("pall", instruct.opcode) == 0)
		print_mstacklist(head);/*
	else if (strcmp("pint", opcode) == 0)
	{


	}
	else if (strcmp("pop", opcode) == 0)
	{

	}
	else if (strcmp("swap", opcode) == 0)
	{


	}
	else if (strcmp("add", opcode) == 0)
	{


	}
	else if (strcmp("nop", opcode) == 0)
	{

	}*/
	else
	{
		fprintf(stderr, "%i: unknown instruction %s\n", lnum, instruct.opcode);
		exit(EXIT_FAILURE);
	}
	return (instruct);
}

/**
 * push - handle push
 * @stack: the head
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{


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
