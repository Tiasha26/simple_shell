#include "shell.h"
/**
 * current_dir - Get the current working directory.
 * Return: A dynamically allocated string containing
 * the current directory path.
 */
char *current_dir()
{
	char *cwd = (char *)malloc(PATH_MAX * sizeof(char));

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("getcwd error");
		free(cwd);
		return (NULL);
	}
	return (cwd);
}
