#include "monty.h"
/**
 * _getline - read a line from a strea
 * @lineptr: pointer to output buffer
 * @n: pointer to size of buffer
 * @stream: stream from which to read
 * Return: number of chars
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buff_size = 256, chars_read = 0;
	int current;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	*lineptr = malloc(sizeof(char) * buff_size);
	while ((current = fgetc(stream)) != EOF)
	{
		if (chars_read + 1 >= buff_size)
		{
			buff_size += 256;
			temp = realloc(*lineptr, buff_size);
			if (!temp)
				return (-1);
			*lineptr = temp;
			*n = buff_size;
		}
			(*lineptr)[chars_read] = current;
			chars_read++;
			if (current == '\n')
				break;
	}
	if (chars_read == 0)
		return (-1);
	(*lineptr)[chars_read] = '\0';
	return (chars_read);
}
