#include "shell.h"
/**
 * replace_variables - Replace special shell variables
 * in the input string.
 * @input: The input string to process.
 * Return: 1 if variables are replaced, 0 otherwise.
 */
int replace_variables(char *input)
{
	char *var;
	char *value;
	char *temp;
	int modified = 0, status = 0;

	if (strstr(input, "$?"))
	{
		temp = strdup(input);

		while ((var = strstr(temp, "$?")) != NULL)
		{
			value = (char *)malloc(12 * sizeof(char));
			snprintf(value, 12, "%d", WEXITSTATUS(status));
			strcpy(var, value);
			strcpy(var + strlen(value), var + 2);
			free(value);
			modified = 1;
		}
		free(temp);
	}

	if (strstr(input, "$$"))
	{
		temp = strdup(input);

		while ((var = strstr(temp, "$$")) != NULL)
		{
			value = (char *)malloc(12 * sizeof(char));
			snprintf(value, 12, "%d", getpid());
			strcpy(var, value);
			strcpy(var + strlen(value), var + 2);
			free(value);
			modified = 1;
		}
		free(temp);
	}

	return (modified);
}
