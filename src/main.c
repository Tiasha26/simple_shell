#include "shell.h"
/**
 * main - Entry point for the shell.
 * Return: 0 on successful execution.
 */
int main(void)
{
	char input[128];

	while (1)
	{
		mydisplay_prompt();
		read_command(input, sizeof(input));
		execute_command(input);
	}
	return (0);
}

