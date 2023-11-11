#include "shell.h"
/**
 * read_file - Read a file and return its content as a string.
 * @file: The file to read.
 * Return: A dynamically allocated string containing
 * the file's content.
 */
char *read_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	size_t size = 0;
	char *input = NULL;

	while (getline(&line, &len, file) != -1)
	{
		size_t line_len = strlen(line);

		size += line_len;
		input = realloc(input, size + 1);
		strcat(input, line);
	}

	if (line)
	{
		free(line);
	}

	return (input);
}
