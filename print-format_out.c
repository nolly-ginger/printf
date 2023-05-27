#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 * @format: charecter string begining and ending in its
 * initial shift state
 * Return: 0
 */
int _printf(const char *format, ...)
{
	selection n[] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%%", print_37},
	};

	va_list args;
	int i = 0, length = 0;

	va_start(args, format);

	while (format[args] != '\0')
	{
	}
}

