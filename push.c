#include "monty.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * push - push an element to the stack
 * @stack: pointer to thhe hesd of the stack
 * @line_number: the line number of the file where the instructions are
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	int n = 0;
	int i;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]) && arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(arg);
	_push(stack, n);
}

/**
 * _push - pushes an  int to the stack
 * @stack: pointer to the head of the stack
 * @n: int to push
 * Return: nothing
 */

void _push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
