#include "monty.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t capacity = *n;
    size_t pos = 0;
    int c;
    char *temp;

    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return (-1);
    }

    if (*lineptr == NULL)
    {
        *lineptr = malloc(capacity);
        if(*lineptr == NULL)
        {
            return -1;
        }
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (pos >= capacity - 1)
        {
            capacity *= 2;
            temp = realloc(*lineptr, capacity);
            if (temp == NULL)
            {
                return -1;
            }
            *lineptr = temp;
            *n = capacity;
        }
        (*lineptr)[pos++] = (char)c;
        if (c == '\n')
        {
            break;
        }
    }
    (*lineptr)[pos] = '\0';
    if (pos == 0 && c == EOF)
    {
        return -1;
    }
    return pos;
}

/**
 * split_line - breaks instruction line into string tokens
 * and puts them in the structure
 *
 * Return: 1 on success or 0 if line is blank
 */
int split_line(void)
{
    char *delimiters = " \n\t\r\a\v";
    int i, spaces = 1;

    if (strcmp(data.line, "\n") == 0)
    {
        return (0);
    }
    for (i = 0; data.line[i] != '\n' && data.line[i] != '#'; i++)
    {
        if (data.line[i] != ' ')
        {
            spaces = 0;
            break;
        }
    }
    if (spaces)
    {
        return (0);
    }
    data.cmd = strtok(data.line, delimiters);
    if (data.cmd[0] == '#')
    {
        return (0);
    }
    data.arg = strtok(NULL, delimiters);
    return (1);
}
/**
 * _free - free stacks
 * @stack: double pointer to top of stack
*/
void _free(stack_t **stack)
{
    stack_t *temp = *stack;

    while (temp != NULL)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

/**
 * execute_instruction - excecutes the opcode
 * @stack: pointer to top of stack
 * Return: 1 or -1
*/

int _execute(stack_t **stack)
{
    void (*f)(stack_t **, unsigned int);

    f = select_opcode(data.cmd);
    if (f == NULL)
    {
        return (-1);
    }
    f(stack, data.num);
    return (1);
}

/**
 * select_opcode - selects opcode
 * @op: opcode
 * Return: pointer to func
*/

void (*select_opcode(char *op))(stack_t **, unsigned int)
{
    unsigned int i;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {NULL, NULL}
    };
    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(instructions[i].opcode, op) == 0)
        {
            return (instructions[i].f);
        }
    }
     return (NULL);
}