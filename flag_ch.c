#include "main.h"

/**
 * flag_characters - Hanfling flags for non-conversion specifiers
 * @sent: String being used to printt he arguments
 * @p: parameter for sent
 *
 * Return: flags
 */

int flag_characters(const char *sent, int *p)
{
	int i, j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const char FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (j = *p + 1; sent[j] != '\0'; j++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (sent[j] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*p = j - 1;

	return (flags);
}
