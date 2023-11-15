#include "shell.h"

#define DEFAULT_SHELL_NAME "shell"
#define SHELL_NAME_DISPLAY_FORMAT "\n%s@%s$%s$$ "

/**
 * @brief Entry point for the shell.
 * @return 0 on successful execution.
 */
int main(void)
{
	char input[256];
	char prompt[PATH_MAX];

	while (1)
	{
		// get the current directory
		char * dir = current_dir();
		snprintf(prompt, sizeof(prompt), SHELL_NAME_DISPLAY_FORMAT, getlogin(), DEFAULT_SHELL_NAME, dir);
		free(dir);
		// display the prompt and execute the command
		mydisplay_prompt(prompt);
		read_command(input, sizeof(input));
		// remove comment
		remove_comments(input);
		// replace vars
		replace_variables(input);
		// execute the command
		execute_command(input);

	}
	return (0);
}

