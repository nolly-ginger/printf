#include "main.h"

/**
 * buffer - entry point for proving the array of characters
 * @array: array list
 * @length: index of the buffer presenting the length of the character string
 *
 * Return: void
 */
void buffer(char array[], int *length)
{
	if (*length > 0)
	{
		write(1, array, *length);
		*length = 0;
	}
}
/**
 * _printf - Produce outputs according to specifier
 * @format: characer string to be printed
 * @...: infinite argument input
 *
 * Return: number of characters printed, excluding '\0'
 */
int _printf(const char *format, ...)
{
	va_list j;
	int i, ptd = 0, prc = 0, width, size;
	int fags, accurate, index = 0;
	char c[BUFF_SIZE];

	va_start(j, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			c[index++] = format[i];
			if (index == BUFF_SIZE)
			{
				buffer(c, &index);
				prc += index;
			}
		}
		else
		{
			buffer(c, &index);
			fags = get_fags(format, &i);
			width = get_width(format, &i, j);
			accurate = get_accurate(format, &i, j);
			size = get_size(format, &i);
			i++;
			ptd = handle_print(format, &i, j, c, fags, width, accurate, size);
			if (ptd == -1)
			{
				buffer(c, &index);
				va_end(j);
				return (-1);
			}
			prc += ptd;
		}
	}
	buffer(c, &index);
	va_end(j);
	return (prc);
}
