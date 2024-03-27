#include "monty.h"
/**
 * print_top - prints data at the top of a stack
 * @stack: pointer to head of the stack
 * @line_number: line_num in the file
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
