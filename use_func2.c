#include "monty.h"
/**
 * len - gets num of elements in a list
 * @stack: double pointer to top of stack
 * Return: number of nodes in the list
*/

size_t len(const stack_t *stack)
{
    size_t count = 0;

    while(stack != NULL)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}