#include "shell.h"
/**
 * setenv_shell - Set an environment variable.
 * @args: Array of command arguments.
 * Return: 0 on success, -1 on failure.
 */
int setenv_shell(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) == -1)
		{
			perror("setenv");
			return (-1);
		}
		return (0);
	}
	my_print("Usage: setenv VARIABLE VALUE\n");
	return (-1);
}
/**
 * unsetenv_shell - Unset an environment variable.
 * @args: Array of command arguments.
 * Return: 0 on success, -1 on failure.
 */
int unsetenv_shell(char **args)
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) == -1)
		{
			perror("unsetenv");
			return (-1);
		}
		return (0);
	}
	my_print("Usage: unsetenv VARIABLE\n");
	return (-1);
}
/**
 * env_shell - Print the environment variables.
 */
void env_shell(void)
{
	char **env = environ;

	while (*env)
	{
		my_print(*env);
		my_print("\n");
		env++;
	}
}
