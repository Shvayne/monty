#include "monty.h"

line_t data = {0, NULL, NULL, NULL, NULL};
/**
 * main - entry point for interpreter
 * @ac: argument count
 * @av: arg vector
 * Return: sucess or failure
*/
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data.fp = fp;
	while ((_getline(&line, &len, fp)) > 0)
	{
		data.line = line;
		data.num += 1;
		if (split_line() == 0)
		{
			continue;
		}
		if (_execute(&stack) == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", data.num, data.cmd);
			fclose(fp);
			_free(&stack);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	_free(&stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
