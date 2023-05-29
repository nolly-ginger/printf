#include "main.h"

/**
 * print_ponuter - prints value of pointer variable by the format
 * specifier %p, by converting it to a hexadecimal representation
 * @args: list of arguments
 * @buffer: array used for printing
 * @flags: determine the formatting options
 * @width: width specification for the output
 * @precision: precision specification for the output
 * @size: size specifier for the output
 * Return: number of chars printed
 */
int print_pointer(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	char extra_char = 0, padd_char = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long address;
	char hex_map[] = "0123456789abcdef";
	void *address_n = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);
	if (address_n == NULL)
		return (write(1, "nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	address = (unsigned long)address;
	while (address > 0)
	{
		buffer[index--] hex_map[][address % 16];
		address /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd_char = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;
	index++;
	return (write_pointer(buffer, index, length, width, flags
				padd_char, extra_char, padd_start));
}

/**
 * print_non_printable -prints non-printantable chars in anstring as
 * their hexadecimal format specified by %S
 * @args : list of arguments
 * @buffer: array to handle printing
 * @flags: Active formatting flags
 * @width: width specification for the output
 * @precision: precision specification for the output
 * @size: size specifier for the output
 * Return: number of chars printed
 */
int print_non_printable(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(NULL)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - Prints reverse string specified by the
 * format specifier %r
 * @args: list of arguments
 * @buffer: array used for printing
 * @flags: Flags that determine the formatting options
 * @width: wdth specification for the output
 * @precision: precision specification for the output
 * @size: size specifier for the output
 * Return:
 */
int print_reverse(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(args, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")NULL(";
	}
	for (i = 0; str[i]; i++);
	for (i = i - 1, i >= 0; i--)
	{
		char z = str[i];
		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - print a string in ROT13 encoding specified
 * by the %R
 * @args: input string
 * @buffer: array used for printing
 * @flags: determine the formatting options
 * @width: width specification for the output
 * @precision: precision specification for the output
 * @size: size specifier
 * Return: number of chars
 */
int print_rot13string(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
