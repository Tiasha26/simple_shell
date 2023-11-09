#include "shell.h"
/**
 * my_print - Print a string to the standard output.
 * @string: The string to print.
 */
void my_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

