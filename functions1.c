#include "main.h"

/**
 * print_unsigned - Prints the unsigned number
 * @types: List the arguments
 * @buffer: Buffer array to handle the print
 * @flags: Calculates the active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Print the number of chars
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints the unsigned number in octal notation
 * @types: List the arguments
 * @buffer: Buffer array to handle the print
 * @flags: Calculates the active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Print the number of chars
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints the unsigned number in hexadecimal notation
 * @types: List the arguments
 * @buffer: Buffer array to handle the print
 * @flags: Calculates the active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Print the number of chars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal notation
 * @types: List the arguments
 * @buffer: Buffer array to handle the print
 * @flags: Calculates the active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Print the number of chars
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints hexadecimal number in lower or upper
 * @types: List the arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle the print
 * @flags: Calculates the active flags
 * @flag_ch: Calculates the active flags
 * @width:width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Print the umber of chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
