#include "shell.h"
/**
 * execute_single_command - Execute a single shell command.
 * @command: The command to execute.
 * Return: The exit status of the executed command.
 */
int execute_single_command(char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error forking process");
		return (-1);
	} else if (child_pid == 0)
	{
		char *args[128];
		int arg_c = 0;
		char *tkn = strtok(command, " ");

		while (tkn != NULL)
		{
			args[arg_c++] = tkn;
			tkn = strtok(NULL, " ");
		}
		args[arg_c] = NULL;

		execvp(args[0], args);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	} else
	{
		int status;

		wait(&status);
		return (WEXITSTATUS(status));
	}
}
/**
 * log_operator - Execute commands with logical operators.
 * @commands: Array of commands.
 * @num_commands: Number of commands in the array.
 * Return: The exit status of the last executed command.
 */
int log_operator(char **commands, int num_commands)
{
	int status = 0;
	int i = 0;

	for (i = 0; i < num_commands; i++)
	{
		char *command = commands[i];

		if (strstr(command, "&&"))
		{
			char *cmd1 = strtok(command, "&&");
			char *cmd2 = strtok(NULL, "&&");

			if (execute_single_command(cmd1) != 0)
			{
				break;
			}
			status = execute_single_command(cmd2);
		}
		else if (strstr(command, "||"))
		{
			char *cmd1 = strtok(command, "||");
			char *cmd2 = strtok(NULL, "||");

			if (execute_single_command(cmd1) == 0)
			{
				break;
			}
			status = execute_single_command(cmd2);
		}
		else
		{
			status = execute_single_command(command);
		}
	}
	return (status);
}
