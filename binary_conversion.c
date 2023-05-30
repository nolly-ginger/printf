#include "main.h"

/**
 * characters - Print the character being changed
 * @types: the arguments
 * @buffer: the array of arguments
 * @flags: the associated flags
 * @width: width of character
 * @precision: precision of the character
 * @size: size of character printed
 *
 * Return: number of characters printed
 */

int character(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char nr = va_arg(types, int);

	return (print_char(nr, buffer, flags, width, precision, size));
}

/**
 * char_string - String evaluated for characters
 * @types: the arguments
 * @buffer: the array of arguments
 * @flags: the associated flags
 * @width: width of character
 * @precision: precision of the character
 * @size: size of character printed
 *
 * Return: number of characters printed
 */

int char_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, j = 0;
	char *sent = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (sent == NULL)
	{
		sent = "(null)";
		if (precision >= 6)
			sent = "      ";
	}

	while (sent[j] != '\0')
		j++;

	if (precision >= 0 && precision < j)
		j = precision;

	if (width > j)
	{
		if (flags & F_MINUS)
		{
			write(1, &sent[0], j);
			for (i = width - j; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - j; i > 0; i--)
				write(1, " ", 1);
			write(1, &sent[0], j);
			return (width);
		}
	}
	return (write(1, sent, j));
}

/**
 * express_percent - Print the percentage sign
 * @types: the arguments
 * @buffer: the array of arguments
 * @flags: the associated flags
 * @width: width of character
 * @precision: precision of the character
 * @size: size of character printed
 *
 * Return: number of characters printed
 */
int express_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * integer_argu - The integer being evaluated
 * @types: the arguments
 * @buffer: the array of arguments
 * @flags: the associated flags
 * @width: width of character
 * @precision: precision of the character
 * @size: size of character printed
 *
 * Return: number of characters printed
 */

int integer_argu(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int neg_nr = 0;
	long int j = va_arg(types, long int);
	unsigned long int nr;

	j = convert_specific(j, size);

	if (j == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nr = (unsigned long int)j;

	if (j < 0)
	{
		nr = (unsigned long int)((-1) * j);
		neg_nr = 1;
	}

	while (nr > 0)
	{
		buffer[i--] = (nr % 10) + '0';
		nr /= 10;
	}
	i++;

	return (write(neg_nr, i, buffer, flags, width, precision, size));
}

/**
 * convert_to_binary - Print unsigned int in binary
 * @types: the arguments
 * @buffer: the array of arguments
 * @flags: the associated flags
 * @width: width of character
 * @precision: precision of the character
 * @size: size of character printed
 *
 * Return: number of characters printed
 */

int convert_to_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int i, j, l, sum;
	unsigned int b[32];
	int measurements;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	l = 2147483648; /* (2 ^ 31) */
	b[0] = j / l;

	for (i = 1; i < 32; i++)
	{
		l /= 2;
		b[i] = (j / l) % 2;
	}

	for (i = 0, sum = 0, measurements = 0; i < 32; i++)
	{
		sum += b[i];
		if (sum || i == 31)
		{
			char c = '0' + b[i];

			write(1, &c, 1);
			measurements++;
		}
	}

	return (measurements);
}
