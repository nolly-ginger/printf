#include "main.h"

/**
 * get_size - calculates size to cast the arg based on the format
 * string and current index
 * @format: pointer to a const charecter string (formatted string)
 * @index: pointer to an integer representing the index of the current
 * charecter in the formatted string
 * Return: Size
 */
int get_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = S_LONG;
	else if (format[curr_index] == 'h')
		size = S_SHORT;
	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;
	return (size);
}
