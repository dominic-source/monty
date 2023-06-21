#ifndef _monty_h_
#define _monty_h_

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
extern ssize_t getline(char **, size_t *n, FILE *);
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *rm_nwl(char *str);
instruction_t instruction(unsigned int, unsigned int *count, FILE *file, ssize_t *);
stack_t *head;
size_t print_mstacklist(const stack_t *h);
size_t mstack_len(const stack_t *h);
stack_t *add_mstackint(stack_t **head, const int n);
void free_stackint(stack_t *head);
int delete_mstack_at_index(stack_t **head, unsigned int index);
int get_opcode(char **opcode, int *data, FILE *file);

#endif
