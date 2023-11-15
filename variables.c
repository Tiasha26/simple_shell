#include "shell.h"

/**
 * @brief Replace special shell variables in the input string.
 * @param input The input string to process.
 * @return The number of a vars replaced.
 */ 
int replace_variables(char *input)
{
	char *var, *value;
	char tmp[32];
	int modified = 0;
	int len;

	while ((var = strstr(input, "$")) != NULL)
	{
		memset(tmp, 0, sizeof(tmp));
		// get a string_var
		size_t len_var = strlen(var);
		char * off = strchr(var, ' ');
		len = (off == NULL) ? strlen(input) - (var - input) : len_var - strlen(off);
	
		// get the value of the var to replace
		strncpy(tmp, var+1, len-1);
		value = getenv(tmp);
		
		if(value == NULL)
			value = strdup(" ");

		// save the rest of string
		char * saved = strdup(var + len);
		// then update the value of a string
		strncpy(var, value, strlen(value));
		strcpy(var + strlen(value), saved);
		// free memory
		free(saved);
		
		modified += 1;
	}

	return (modified);
}
