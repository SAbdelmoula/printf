#include "main.h"

/**
 * get_size - calculates Size to cast the arguments
 * @format: format the string in which to Print the arguments
 * @i: list the arguments to be printed.
 * Return: Precision
 */
int get_size(const char *format, int *i)
{
	int cur_ii = *i + 1;
	int size = 0;

	if (format[cur_ii] == 'l')
		size = S_LONG;
	else if (format[cur_ii] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_ii - 1;
	else
		*i = cur_ii;

	return (size);
}
