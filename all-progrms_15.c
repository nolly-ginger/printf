#include "main.h"

/**
 * print_all - prints an argument according to its type
 * function processes fomart string, indentifes format specifiers and calls
 * corresponding handling funcs to print args based on their types
 * @fmt: pointer to a const char string (formatted string)
 * @index: pointer to an integer representing the index of current
 * charecter in the format string
 * @args: list of arguments to be printed
 * @buf: a buffer array used to handle the print
 * @flags: integer representing the active flags for formatting
 * @width: width specifier for formatting
 * @precision: precision specifier for formatting
 * @size: size specifier for formatting
 * Return: 1 or 2
 */
int print_all(const char *fmt, int *index, va_list args, char buf[],
		int flags, int width, int precision, int size)
{
	int i, unkwn_len = 0, printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', character}, {'s', char_string}, {'%', express_percent},
		{'i', integer_argu}, {'d', integer_argu}, {'b', convert_to_binary},
		{'u', unsigned_int}, {'o', octal_int}, {'x', int_hex},
		{'X', upper_hexa_int}, {'p', print_pointer},
		{'S', print_non_printable}, {'r', print_reverse},
		{'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*index] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buf, flags, width, precision, size));
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unkwn_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unkwn_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unkwn_len += write(1, &fmt[*index], 1);
		return (unkwn_len);
	}
	return (printed_chars);
}
