#include "shell.h"
/**
 * execute_command - Execute a command.
 * @input: The command to execute.
 */
void execute_command(const char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		my_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[120];
		int arg_c = 0;
		char *tkn = strtok((char *)input, " ");

		while (tkn != NULL)
		{
			args[arg_c++] = tkn;
			tkn = strtok(NULL, " ");
		}
		args[arg_c] = NULL;
		execvp(args[0], args);

		my_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	} else
	{
		wait(NULL);
	}
}
