#include "shell.h"

/**
 * read_command - Read a command from the standard input.
 * @input: Buffer to store the command.
 * @size: Size of the buffer.
 */
void read_command(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
