#include "shell.h"

/**
 * replace_variables - Replace special shell variables in the input string.
 * @input: The input string to process.
 * Return: The number of a vars replaced.
 */
int replace_variables(char *input)
{
	char *var, *value;
	char tmp[32];
	int modified = 0;
	int len;

	while ((var = strstr(input, "$")) != NULL)
	{
		size_t len_var = strlen(var);
		char *off = strchr(var, ' ');/** get a string_var */
		char *saved = strdup(var + len);/** save the rest of string */

		memset(tmp, 0, sizeof(tmp));
		len = (off == NULL) ? strlen(input) - (var - input) : len_var - strlen(off);
		/** get the value of the var to replace */
		strncpy(tmp, var + 1, len - 1);
		value = getenv(tmp);
		if (value == NULL)
			value = strdup(" ");
		/** then update the value of a string */
		strncpy(var, value, strlen(value));
		strcpy(var + strlen(value), saved);
		/** free memory */
		free(saved);
		modified += 1;
	}
	return (modified);
}
