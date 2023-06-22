#include "monty.h"

/**
 * print_mstacklist - print out the doubly link list
 * @h: the head
 * @ln: line number
 */
void print_mstacklist(stack_t **h, unsigned int ln)
{
        stack_t *current;
        unsigned int i;

        current = *h;
        for (i = 0; current != NULL; i++)
        {
                printf("%i\n", current->n);
                current = current->next;
        }
	if (i > ln)
		return;
}

/**
 * mstack_len - length of the stack
 * @h: head
 * @ln: line number
 */
void mstack_len(stack_t **h, unsigned int ln)
{
        stack_t *current;
        unsigned int i;
	int count = 0;

        current = *h;
        for (i = 0; i < ln && current != NULL; i++)
        {
                count++;
                current = current->next;
        }
	printf("%i\n", count);
}

/**
 * add_mstackint - add node at the beginning
 * @head: head of the linked list
 * @ln: line number
 *
 */
void add_mstackint(stack_t **head, unsigned int n)
{
        stack_t *new;

        new = malloc(sizeof(stack_t));
        if (new == NULL && n)
	{
		error(4, n, NULL);
		exit(EXIT_FAILURE);
	}
        if (*head == NULL)
        {
                new->next = NULL;
                new->prev = NULL;
                *head = new;
        }
        else
        {
                (*head)->prev = new;
                new->next = *head;
                new->prev = NULL;
                *head = new;
        }

}

/**
 * free_stackint - free linked list
 * @head: the head of the list
 * @ln: line number
 */
void free_stackint(stack_t **head, unsigned int ln)
{
        stack_t *current = *head;
        unsigned int i;

        for (i = 0; i < ln && *head != NULL; i++)
        {
                current = *head;
                *head = (*head)->next;
                free(current);
        }
}

/**
 * delete_mstack_at_index - delete node at index
 * @head: the head
 * @index: index of node to delete
 */
void delete_mstack_at_index(stack_t **head, unsigned int index)
{
        stack_t *current = *head, *del;
        unsigned int i;

        if (current == NULL || head == NULL)
                return;
        else if (index == 0 && current->next == NULL)
        {
                free(current);
                *head = NULL;
        }
        else if (index == 0 && current != NULL)
        {
                del = current;
                current->next->prev = NULL;
                *head = current->next;
                free(del);
        }
        else if (index > 0)
        {
                for (i = 0; i < (index - 1) && current != NULL; i++)
                        current = current->next;
                if (current == NULL && index > i)
                        return;
                del = current->next;
                current->next = current->next->next != NULL ? current->next->next : NULL;
                if (current->next != NULL)
                        current->next->prev = current;
                free(del);
        }
}
