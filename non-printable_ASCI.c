#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printable - Check whether the character is printable
 * @p: character to be printed
 *
 * Return: 1 if the character is printable
 * 0 if it is not printable
 */

int printable(char p)
{
	if (p >= 32 && p < 127)
		return (1);

	return (0);
}

/**
 * hexa_code - Add the hexadecimal function to the character
 * @array: array of characters
 * @j: index when starting to add code
 * @code: ASCI code
 *
 * Return: Always 3(Success)
 */

int hexa_code(char code, char array[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;

	array[i++] = '\\';
	array[i++] = 'x';

	array[i++] = map_to[code / 16];
	array[i] = map_to[code % 16];

	return (3);
}

/**
 * verify - Confirms whether character isdigit
 * @d: character being tested
 *
 * Return: 1 if digit, else 0
 */

int verify(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * convert_nr - Convering the number to a different size
 * @nr: the number
 * @size: the new value
 *
 * Return: new value of nr
 */

long int convert_nr(long int nr, int size)
{
	if (size == S_LONG)
		return (nr);
	else if (size == S_SHORT)
		return (short(nr));

	return ((int)nr);
}

/**
 * convert_specific - Change the number to a specific size
 * @nr: number
 * @size: new size allocation
 *
 * Return: new size of nr
 */

long int convert_specific(unsigned long int nr, int size)
{
	if (size == S_LONG)
		return (nr);
	else if (size == S_SHORT)
		return ((unsigned short)nr);

	return ((unsigned int)nr);
}
