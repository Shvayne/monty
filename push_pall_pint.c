#include "monty.h"
/**
 * push - push an element to the top of the  stack
 * @stack: double pointer to top of stack
 * @n: value to push
 * return: nothing
*/
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int i, n;

	if (new_node == NULL)
	{
		free(data.line);
		_free(stack);
		fclose(data.fp);
		fprintf(stderr, "Error: Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (data.arg == NULL)
	{
		free(new_node);
		free(data.line);
		_free(stack);
		fclose(data.fp);
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; data.arg[i]; i++)
	{
		if (data.arg[i] == '+' || data.arg[i] == '-')
			continue;
		else if (!isdigit(data.arg[i]))
		{
			free(new_node);
			free(data.line);
			_free(stack);
			fclose(data.fp);
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(data.arg);
	new_node->n = n;
	if (*stack != NULL)
	{
		new_node->next = *stack;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}

/**
 * pall - prints data of a stack
 * @stack: double pointer to top
 * @line_num: line number of the  instruction
*/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	(void)line_num;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - print value at the top of the stack
 * @stack: double pointer to head of stack
 * @line_num: instruction line
*/
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		free(data.line);
		fclose(data.fp);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
