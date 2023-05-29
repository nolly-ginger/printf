#include "main.h"

/**
 * _putchar - writes the charecter c to std output
 * @c: character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printf_i - prints an int using _putchar
 * function that handles/uses the %i conversion specifiers
 * @args: arguments to print
 * Return: integer value
 */
int printf_i(va_list args)
{
	int a = va_arg(args, int);
	int n, n2 = n % 10, n3, value = 1;
	int a = 1;

	i = n / 10;
	n = i;
	if (n2 < 0)
	{
		_putchar('_');
		n = -n;
		i = -i;
		n2 = -n2;
		a++;
	}
	if (n > 0)
	{
		while (value > 0)
		{
			n3 = n / value;
			_putchar(n3 + '0');
			n = n - (n3 * value);
			value = value / 10;
			a++;
		}
	}
	_putchar(n2 + '0');
	return (a);
}
/**
 * printf_d - prints a decimal value using _putchar
 * function that handles/uses the %d conversion specifiers
 * @args: arguments to print
 * Return: decimal value
 */
int printf_d(va_list args)
{
	int input = va_arg(args, int);
	int n, lastDigit = input % 10, n3;
	int count = 1;
	int value = 1;

	input = input / 10;
	n = input;

	if  (lastDigit < 0)
	{
		_putchar('_');
		n = -n;
		input = -input;
		lastDigit = -lastDigit;
		count++;
	}
	if (n > 0)
	{
		while (n / 10 != 0)
		{
			value = value * 10;
			n = n / 10;
		}
		n = input;
		while (value > 0)
		{
			lastDigit = n / value;
			_putchar(lastDigit + '0');
			n = n - (lastDigit * value);
			value = value / 10;
			count++;
		}
	}
	_putchar(lastDigit + '0');
	return (count);
}
