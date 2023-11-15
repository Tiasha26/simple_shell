#include "shell.h"
/**
 * handle_builtin - Handle built-in shell commands.
 * @args: Array of command arguments.
 * Return: 1 if the command is a built-in and was handled, 0 otherwise.
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		int status = (args[1] != NULL) ? atoi(args[1]) : 0;
		exit(status);
		return (1);
	} else if (strcmp(args[0], "env") == 0)
	{
		env_shell();
		return (1);
	} else if (strcmp(args[0], "setenv") == 0)
	{
		return (handle_setenv(args));
	} else if (strcmp(args[0], "unsetenv") == 0)
	{
		return (handle_unsetenv(args));
	} else if (strcmp(args[0], "cd") == 0)
	{
		cd_shell(args[1]);
		return (1);
	} else if (strcmp(args[0], "alias") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * handle_setenv - Handle the 'setenv' command.
 * @args: Array of command arguments.
 * Return: 1 if the command is handled, 0 otherwise.
 */
int handle_setenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		char *setenv_args[3];

		setenv_args[0] = args[0];
		setenv_args[1] = args[1];
		setenv_args[2] = args[2];
		setenv_shell(setenv_args);
	} else
	{
		my_print("Usage: setenv VARIABLE VALUE\n");
	}
	return (1);
}

/**
 * handle_unsetenv - Handle the 'unsetenv' command.
 * @args: Array of command arguments.
 * Return: 1 if the command is handled, 0 otherwise.
 */
int handle_unsetenv(char **args)
{
	if (args[1] != NULL)
	{
		char *unsetenv_args[2];

		unsetenv_args[0] = args[0];
		unsetenv_args[1] = args[1];
		unsetenv_shell(unsetenv_args);
	} else
	{
		my_print("Usage: unsetenv VARIABLE\n");
	}
	return (1);
}
