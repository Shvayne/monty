#include "monty.h"

/**
 * pop - remove element at the top of the stack
 * @stack: double pointer to top of stack
 * @line_num: line number of instruction
*/

void pop(stack_t **stack, unsigned int line_num)
{
    stack_t *new_node = *stack;
    if (*stack == NULL)
    {
        free(data.line);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
        exit(EXIT_FAILURE);
    }
    *stack = (*stack)->next;
    free(new_node);
}
/**
 * swap - swap the n values of two nodes in a stack
 * @stack: head of stack
 * @line_num: instruction line
*/
void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *first = *stack, *second;

    if (*stack == NULL || len(*stack) < 2)
    {
        free(data.line);
        _free(stack);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    second = (*stack)->next;
    first->next = second->next;
    first->prev = second;
    second->prev = NULL;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    *stack = second;
}

/**
 * add - adds the data of the top two elements in the stack
 * @stack: double pointer to head of stack
 * @line_num: line number of instruction
*/

void add(stack_t **stack, unsigned int line_num)
{
    stack_t *second, *first = *stack;

    if (*stack == NULL || len(*stack) < 2)
    {
        free(data.line);
        _free(stack);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    second = (*stack)->next;
    second->n += first->n;
    pop(stack, line_num);
}

/**
 * nop - does nothing
 * @stack: double ptr to head of stack
 * @line_num: instruction line_num
*/

void nop(__attribute__((unused)) stack_t **stack, unsigned int line_num)
{
    (void)line_num;
}