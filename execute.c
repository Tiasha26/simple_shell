
#include "shell.h"

/**
 * execute_command - Execute a command.
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
	}
	else
	{
		int arg_c = 0;
		char *tkn = strtok((char *)input, " ");

		while (tkn != NULL)
		{
			args[arg_c++] = tkn;
			tkn = strtok(NULL, " ");
		}
		args[arg_c] = NULL;

		// the child run the command
		if (child_pid == 0) {

			// check if there's an alias
			char *alias = NULL;
			if((alias = get_alias(args[0])) != NULL)
				args[0] = alias;

			// try to run the command with alias replaced
			if(handle_builtin(args) == 0)
				if(execvp(args[0], args) == -1)
					perror("Error when executing command");
			exit(0);
		} else {
			if(strcmp(args[0], "exit") == 0)
				exit(EXIT_SUCCESS);
			else if(strcmp(args[0], "cd") == 0)
				cd_shell(args[1]);
			else if(strcmp(args[0], "alias") == 0) {
				handle_alias((const char **)args);
			}

			wait(NULL);
		}
	}
}
