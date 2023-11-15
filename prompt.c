#include "shell.h"

#define DEFAULT_PROMPT_NAME "shell$ "

/**
 * mydisplay_prompt - Display the shell prompt.
 * @prompt_name: prompt name
 */
void mydisplay_prompt(const char *prompt_name)
{
	if (prompt_name == NULL)
		my_print(DEFAULT_PROMPT_NAME);
	else
		my_print(prompt_name);
}
