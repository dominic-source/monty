#include "monty.h"

void get_opcode(char **opcode, int* data, char **lptr, size_t *n);
extern stack_t *head;

/**
 * main - interprete monty
 * @argv: arguments
 * @argc: argument counts
 * Return: 0 or 1
 */
int main(int argc, char* argv[])
{
	char *fname;
	char *lineptr = NULL;//this is for your getline function
	size_t n = 0; //this is for your getline function
	int lnum = 0;
	FILE *file;
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
	while (1)
	{
		lnum++;
		interprete = instruction(lnum, &count, &lineptr, &n);
		interprete.f();
	}
	fclose(file);
	return (0);
}

/**
 * instruction - push an element to the stack
 * @opcode: opcode to interprete
 */
instruction_t instruction(unsigned int lnum, unsigned int count, char **l, size_t *n)
{
	char *opcode = NULL;
	int data = 0;
	instruction_t instruct;

	get_opcode(&opcode, &data, lineptr, n); //this where i moved your function to
	instruct.opcode = opcode;

	if (strcmp("push", instruct.opcode) == 0)
		add_mstackint(&head, data);
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
		fprintf(stderr, "%i: unknown instruction %s", lnum, opcode);
		exit(EXIT_FAILURE);
	}
	return (instruct);
}
