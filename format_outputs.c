#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
	int *i;
	char c;

	va_start(j, format);

	while (*format != '\0')
		*format++;

	return (c)
}
