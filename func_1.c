#include "monty.h"

/**
 * print_mstacklist - print out the doubly link list
 * @h: the head
 * Return: the count of the list
 */
size_t print_mstacklist(const stack_t *h)
{
        const stack_t *current;
        size_t i, count = 0;

        current = h;
        for (i = 0; current != NULL; i++)
        {
                count++;
                printf("%i\n", current->n);
                current = current->next;
        }

        return (count);
}

/**
 * mstack_len - length of the stack
 * @h: head
 * Return: length
 */
size_t mstack_len(const stack_t *h)
{
        const stack_t *current;
        size_t i, count = 0;

        current = h;
        for (i = 0; current != NULL; i++)
        {
                count++;
                current = current->next;
        }
        return (count);
}

/**
 * add_mstackint - add node at the beginning
 * @head: head of the linked list
 * @n: the data to add in the created node
 * Return: the new node
 */
stack_t *add_mstackint(stack_t **head, const int n)
{
        stack_t *new;

        new = malloc(sizeof(stack_t));
        if (new == NULL)
                return (NULL);
        if (*head == NULL)
        {
                new->n = n;
                new->next = NULL;
                new->prev = NULL;
                *head = new;

        }
        else
        {
                new->n = n;
                (*head)->prev = new;
                new->next = *head;
                new->prev = NULL;
                *head = new;
        }

        return (new);
}

/**
 * free_stackint - free linked list
 * @head: the head of the list
 */
void free_stackint(stack_t *head)
{
        stack_t *current = head;
        int i;

        for (i = 0; head != NULL; i++)
        {
                current = head;
                head = head->next;
                free(current);
        }
}

/**
 * delete_mstack_at_index - delete node at index
 * @head: the head
 * @index: index of node to delete
 * Return: 1 or -1
 */
int delete_mstack_at_index(stack_t **head, unsigned int index)
{
        stack_t *current = *head, *del;
        unsigned int i;

        if (current == NULL || head == NULL)
                return (-1);
        else if (index == 0 && current->next == NULL)
        {
                free(current);
                *head = NULL;
                return (1);
        }
        else if (index == 0 && current != NULL)
        {
                del = current;
                current->next->prev = NULL;
                *head = current->next;
                free(del);
                return (1);
        }
        else if (index > 0)
        {
                for (i = 0; i < (index - 1) && current != NULL; i++)
                        current = current->next;
                if (current == NULL && index > i)
                        return (-1);
                del = current->next;
                current->next = current->next->next != NULL ? current->next->next : NULL;
                if (current->next != NULL)
                        current->next->prev = current;
                free(del);
                return (1);
        }
        return (-1);
}
