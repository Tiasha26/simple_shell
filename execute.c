#include "shell.h"
/**
 * execute_child_process - Executes a command in the shell.
 * @args: Array of command arguments.
 */
void execute_child_process(char **args)
{
	char *alias = get_alias(args[0]);

	if (alias != NULL)
	{
		args[0] = alias;
	}
	if (handle_builtin(args) == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error when executing command");
		}
	}
	exit(EXIT_SUCCESS);
}
/**
 * handle_builtin_execution - Handles the execution of built-in commands.
 * @args: Array of command arguments.
 */
void handle_builtin_execution(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	} else if (strcmp(args[0], "cd") == 0)
	{
		cd_shell(args[1]);
	} else if (strcmp(args[0], "alias") == 0)
	{
		handle_alias((const char **)args);
	}
}
/**
 * execute_command - Executes a command in the shell.
 * @input: The command to execute.
 */
void execute_command(const char *input)
{
	char *args[120];
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		my_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	} else
	{
		int arg_c = 0;
		char *tkn = strtok((char *)input, " ");

		while (tkn != NULL)
		{
			args[arg_c++] = tkn;
			tkn = strtok(NULL, " ");
		}
		args[arg_c] = NULL;
		if (child_pid == 0)
		{
			execute_child_process(args);
		} else
		{
			handle_builtin_execution(args);
			wait(NULL);
		}
	}
}

