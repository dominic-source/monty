#include "monty.h"

void get_opcode(char **opcode, int* data);
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
	int file, lnum = 0;
	char *opcode = NULL;
	int data = 0;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fname = argv[1];
	file  = open(fname, O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (strcmp(argv[1], opcode) != 0)
		{
			fprintf(stderr, "%i: unknown instruction %s", lnum, opcode);
			exit(EXIT_FAILURE);
		}
	       get_opcode(&opcode, &data);
	}
	return (0);
}
