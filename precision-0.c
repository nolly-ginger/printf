#include "main.h"

/**
 * _precision - handles precision for non-custom
 * conversion specifiers
 * @format: pointer to a const charecter string (formatted string)
 * in which arguments will be printed
 * @index: pointer to an integer representing index of current char
 * in the format string
 * @args: variable argument list (contains args to be printed)
 * Return: Precision
 */
int _precision(const char *format, int *index, va_list args)
{
	int next_index = *index + 1;
	int precision = -1;

	if (format[next_index] != '.')
		return (precision);
	precision = 0;
	for (next_index += 1; format[next_index] != '\0'; next_index++)
	{
		if (verify(format[next_index]))
		{
			precision *= 10;
			precision += format[next_index] - '0';
		}
		else if (format[next_index] == '*')
		{
			next_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*index = next_index - 1;
	return (precision);
}
