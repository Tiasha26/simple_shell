#include "shell.h"
/**
 * change_dir - Change the current working directory.
 * @path: The path to the directory to change to.
 * Return: 0 on success, -1 on failure.
 */
int change_dir(char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

/**
 * cd_shell - Change the current working directory.
 * @path: The path to the directory to change to.
 */
void cd_shell(char *path)
{
	char *cwd = current_dir();

	if (path == NULL)
	{
		path = getenv("HOME");
	}
	if (change_dir(path) == 0)
	{
		char *setenv_args[3];

		setenv_args[0] = "PWD";
		setenv_args[1] = cwd;
		setenv_args[2] = 0;
		setenv_shell(setenv_args);
	}
	free(cwd);
}
