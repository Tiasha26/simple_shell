#include "shell.h"
/**
 * remove_comments - Remove comments from a string by
 * truncating at the '#' character.
 * @input: The input string to remove comments from.
 */
void remove_comments(char *input)
{
	char *comment = strchr(input, '#');

	if (comment != NULL)
	{
		*comment = '\0';
	}
}
