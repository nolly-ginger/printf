#include "main.h"

/**
 * buffer - output of contents being printed to buffer
 * @array: array of buffer
 * @arr_index: index of the printing out the next character
 *
 * Return: void
 */

void buffer(char array[], int *arr_index)
{
	if (*arr_index > 0)
		write(1, &array[0], *arr_index);

	*arr_index = 0;
}

/**
 * _printf - returning the number of characters printed
 * @format: the string of characters
 * @...: infinite arguments input
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, k = 0, p = 0, flags;
	int width, precision, size, arr_index = 0;
	va_list j;
	char c[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(j, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			c[arr_index++] = format[i];
			if (arr_index == BUFF_SIZE)
			{
				buffer(c, &arr_index);
			}
			p++;
		}
		else
		{
			buffer(c, &arr_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, j);
			precision = get_precision(format, &i, j);
			size = get_size(format, &i);
			++i;
			k = handle_print(format, &i, j, c, flags, width, precision, size);

			if (k == -1)
				return (-1);

			p += k;
		}
	}
	buffer(c, &arr_index);
	va_end(j);
	return (p);
}
