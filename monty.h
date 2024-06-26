#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct line_s
{
        int num;
        char *line;
        char *cmd;
        char *arg;
        FILE *fp;
}line_t;
extern line_t data;

int split_line(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _free(stack_t **stack);
int _execute(stack_t **stack);
void (*select_opcode(char *op))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
size_t len(const stack_t *stack);
void add(stack_t **stack, unsigned int line_num);
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);