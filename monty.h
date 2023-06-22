#ifndef _monty_h_
#define _monty_h_

#include <ctype.h>
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
void error(int, unsigned int, char *);
char *rm_nwl(char *str);
int find_func(char **lptr, instruction_t *instruct, int *data);
int instruction(unsigned int, FILE *file, ssize_t *, char **, stack_t **);
int ex;
void print_mstacklist(stack_t **h, unsigned int l);
void mstack_len(stack_t **h, unsigned int l);
void add_mstackint(stack_t **head, unsigned int n);
void free_stackint(stack_t **head, unsigned int n);
void delete_mstack_at_index(stack_t **head, unsigned int index);
stack_t *get_mstack_at_index(stack_t *head, unsigned int index);
void print_end_mstacklist(stack_t **h, unsigned int ln);
void pop_end_mstacklist(stack_t **h, unsigned int ln);
void swap_mstacklist(stack_t **h, unsigned int ln);
void add_mstacklist(stack_t **h, unsigned int ln);
void nop_mstacklist(stack_t **h, unsigned int ln);
void sub_mstacklist(stack_t **h, unsigned int ln);
void mul_mstacklist(stack_t **h, unsigned int ln);
void mod_mstacklist(stack_t **h, unsigned int ln);

#endif
