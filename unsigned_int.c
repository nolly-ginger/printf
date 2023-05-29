#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * unsigned_int - Print the unsigned integer value
 * @types: arguments
 * @buffer: array of buffer
 * @flags: flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 *
 * Returnn: the character number printed
 */

int unsigned_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);

	nr = convert_size_unsgnd(nr, size);

	if (nr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[i--] = (nr % 10) + '0';
		nr /= 10;
	}
	i++;

	return (write(0, i, buffer, flags, width, precision, size));
}

/**
 * octal_int - Print the integer in octal
 * @types: arguments
 * @buffer: array of buffer
 * @flags: flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 *
 * Returnn: the character number printed
 */

int octal_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);
	unsigned long int nr2 = nr;

	UNUSED(width);

	nr = convert_size_unsgnd(nr, size);

	if (nr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[i--] = (nr % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && nr2 != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * int_hex - Printing an integer in hexadecial form
 * @types: arguments
 * @buffer: array of buffer
 * @flags: flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 *
 * Returnn: the character number printed
 */

int int_hex(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * upper_hexa_int - Print the unsigned integer in upper hexa notation
 * @types: arguments
 * @buffer: array of buffer
 * @flags: flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 *
 * Returnn: the character number printed
 */

int upper_hexa_int(va_list types, char buffer[],
		flags, width, precision, size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * hexa_int - Print the integer in lower or lower hex notation
 * @map_to: array value mapping numbers
 * flag_ch: active flasg in full
 * @types: arguments
 * @buffer: array of buffer
 * @flags: flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 *
 * Returnn: the character number printed
 */

int hexa_int(va_list types, char buffer[], char map_to[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);
	unsigned long int nr2 = nr;

	UNUSED(width);

	nr = conver_size_unsgnd(nr, size);

	if (nr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[i--] = map_to[nr % 16];
		nr /= 16;
	}

	if (flags & F_HASH && nr2 != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
