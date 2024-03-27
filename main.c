#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"
#include <string.h>

/**
 * open_file - opens file
 * @file_path: path to the file containing monty byte code
 * Return: file pointer
 */
FILE *open_file(const char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", file_path);
	}
	return (file);
}

/**
 * check_arguments - checks if the correct number of commsnds are provided
 * @argc: argument count
 * Return: EXIT SUCCESS or EXIT FAILURE
 */
int check_arguments(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * process_file - reads file line by line and executes
 * @file: file pointer
 * Return: EXIT SUCESS or EXIT FAILURE
 */
int process_file(FILE *file)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t line_len;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int found;
	char *opcode;
	instruction_t *inst;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", print_top},
		{NULL, NULL}
	};

	while ((line_len = _getline(&buffer, &bufsize, file)) != -1)
	{
		line_number++;
		opcode = strtok(buffer, " \n");

		if (opcode == NULL || *opcode == '#')
			continue;
		found = 0;
		for (inst = instructions; inst->opcode != NULL; inst++)
		{
			if (strcmp(opcode, inst->opcode) == 0)
			{
				inst->f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown intructin %s\n", line_number, opcode);
			free(buffer);
			return (EXIT_FAILURE);
		}
	}
	free(buffer);
	return (EXIT_SUCCESS);
}

/**
 * main - entry
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCESS or FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int status;

	if (check_arguments(argc) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	file = open_file(argv[1]);
	if (file == NULL)
	{
		return (EXIT_FAILURE);
	}

	status = process_file(file);
	fclose(file);
	return (status);
}
