#include "monty.h"
/**
 * sub - subtract two nodes
 * @stack: head of list
 * @line_num: line number for error reporting
*/
void sub(stack_t **stack, unsigned int line_num)
{
    stack_t *second, *first = *stack;

    if (*stack == NULL || len(*stack) < 2)
    {
        free(data.line);
        _free(stack);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    second = first->next;
    second->n -= first->n;
    pop(stack, line_num);
}

/**
 * div - performs division operation on two nodes
 * @stack: double pointer to head
 * @line_num: line number of instruction
*/

void _div(stack_t **stack, unsigned int line_num){
    stack_t *second, *first = *stack;

    if (*stack == NULL || len(*stack) < 2)
    {
        free(data.line);
        _free(stack);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {   _free(stack);
        free(data.line);
        fclose(data.fp);
        fprintf(stderr, "L%d: division by zero\n", line_num);
        exit(EXIT_FAILURE);
    }
    second = first->next;
    second->n /= first->n;
    pop(stack, line_num);
}
/**
 * mul - multiplies two elements in a stack
 * @stack: double pointer to head of stack
 * @line_num: line for error reporting
*/
void mul(stack_t **stack, unsigned int line_num)
{
     stack_t *second;

    if (*stack == NULL || len(*stack) < 2)
    {
        _free(stack);
        free(data.line);
        fclose(data.fp);
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    second = (*stack)->next;
    second->n *= (*stack)->n;
    pop(stack, line_num);
}