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
	unsigned int lnum = 0;
	ssize_t line = 0;
	FILE *file;

	head = NULL;
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
		exit(EXIT_FAILURE);
	}
	while (line != -1)
	{
		lnum++;
		instruction(lnum, file, &line);
	}
	fclose(file);
	free_stackint(&head, lnum);
	return (0);
}

/**
 * instruction - push an element to the stack
 * @opcode: opcode to interprete
 */
void instruction(unsigned int lnum, FILE *file, ssize_t *l)
{
	char *lptr;
	stack_t *current;
	instruction_t instruct;
        size_t n;
	int data = 0;

	*l = getline(&lptr, &n, file);
	if (*l == -1)
		exit(EXIT_SUCCESS);
	find_func(&lptr, &instruct, &data);
	if (instruct.opcode != NULL && strcmp(instruct.opcode, "") != 0)
	{
		if (instruct.f == NULL)
		{
			error(3, lnum, instruct.opcode);
			exit(EXIT_FAILURE);
		}
		instruct.f(&head, lnum);

		if (strcmp(instruct.opcode, "push") == 0)
		{
			current = head;
			current->n = data;
		}
	}
}

/**
 * find_func - handle push
 * @stack: the head
 * @line_number: the line number
 */
void find_func(char **lptr, instruction_t *instruct, int *data)
{
	char *token;
	int flag = 0, i;

	instruction_t arr[] = {
		{"push", add_mstackint},
		{"pall", print_mstacklist},
		{"pint", print_end_mstacklist},
		{"pop", pop_end_mstacklist},
		{"swap", swap_mstacklist},
		{NULL, NULL},
	};

	instruct->opcode = strtok(*lptr, " ");
        token = strtok(NULL, " ");

	if (token != NULL)
                *data = atoi(token);
	instruct->opcode = rm_nwl(instruct->opcode);

	for (i = 0; arr[i].opcode != NULL; i++)
	{
		if (strcmp(arr[i].opcode, instruct->opcode) == 0)
		{
			flag = 1;
			instruct->f = arr[i].f;
			break;
		}
	}
	if (!flag)
		instruct->f = NULL;

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
