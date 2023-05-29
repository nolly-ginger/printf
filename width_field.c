#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * width_ch - Finding with of the printed character
 * @str: string being checked for width
 * @argu: Arguments list to be printed
 * @list: list of argu
 *
 * Return: width of character
 */

int width_ch(const char *str, int *argu, va_list list)
{
	int i, j = 0;

	for (i = *argu + 1; str[i] != '\0'; i++)
	{
		if (is_digit(str[i]))
		{
			width *= 10;
			width += str[i] - '0';
		}
		else if (str[i] == '*')
		{
			i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*argu = i - 1;
	return (width);
}
