#include "main.h"

/**
 * print_char - handles printing of as ingle char
 * @c: char typs
 * @buffer: array to handle printing
 * @flags: indicate formatting options
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */
int print_char(char c, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1],
						width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
					+ write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * print_number - handles the printing of a number (int value)
 * @is_negative: indicator of whether the number is negative
 * @index: indicates where the number starts in the buffer
 * @buffer: array to store number and padding
 * @flags: indicate formatting options
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of charecters printed
 */
int print_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_chrs = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_chrs = '-';
	else if (flags & F_PLUS)
		extra_chrs = '+';
	else if (flags & F_SPACE)
		extra_chrs = ' ';
	return (print_num(index, buffer, flags, width, precision,
				length, padd, extra_chrs));
}

/**
 * print_num - helper function used by print_number function,
 * it writes a number using a buffer
 * @index: indicates where the number starts in the buffer
 * @buffer: array to store number and padding
 * @flags: indicate formatting options
 * @width: width specifier
 * @precision: precision specifier
 * @length: length of the number beng printed
 * @padd: charecter used for padding
 * @extra_chars: extra charecters to beincluded in the outpu
 * Return: number of charecters
 */
int print_num(int index, char buffer[], int flags, int width,
		int precision, int length, char padd,
		char extra_chars)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] ==
			'0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_chars != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_chars)
				buffer[--index] = extra_chars;
			return (write(1, &buffer[index], length) +
					write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_chars)
				buffer[--index] = extra_chars;
			return (write(1, &buffer[1], i - 1)
					+ write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_chars)
				buffer[--padd_start] = extra_chars;
			return (write(1, &buffer[padd_start], i - padd_start)
					+ write(1, &buffer[index], length - (1 - padd_start)));
	}
	if (extra_chars)
		buffer[--index] = extra_chars;
	return (write(1, &buffer[index], length));
}
/**
 * print_unsigned_number - prints an unsigned number value
 * @is_negative: indicator of whether number is negative
 * @index: indicates where the number starts in the buffer
 * @buffer: array to store number and padding
 * @flags: indicate formatting options
 * @width: width specifier
 * @precision: precision specifier
 * @size: size of specifier
 * Return: number of chars printed
 */
int print_unsigned_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) +
					write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) +
					write(1, &buffer[index], len));
		}
	}
	return (write(1, &buffer[index], len));
}
/**
 * pri_pointer - handles the printing of a memory address
 * @buffer: array to store number and padding
 * @index: indicates where the number starts in the buffer
 * @length: length of the number being printed
 * @width: width specifier
 * @flags: indicate formatting options
 * @padd: character used for padding
 * @extra_chars: extra character to be included in the output
 * @padd_start: start of padding
 * Return: number of chars printed
 */
int pri_pointer(char buffer[], int index, int length, int width,
		int flags, char padd, char extra_chars,
		int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_chars)
				buffer[--index] = extra_chars;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_chars)
				buffer[--index] = extra_chars;
			return (write(1, &buffer[3], i - 3) +
					write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_chars)
				buffer[--padd_start] = extra_chars;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_chars)
		buffer[--index] = extra_chars;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
