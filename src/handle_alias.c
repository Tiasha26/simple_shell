#include "shell.h"
/**
 * handle_alias - Handle alias related operations.
 * @input: The input command.
 */
void handle_alias(char *input)
{
	if (strstr(input, "alias") == input)
	{
		char *alias_name = strtok(input, "\n");

		if (alias_name != NULL)
		{
			char *alias_value = strtok(NULL, "\n");

			if (alias_value != NULL)
			{
				set_alias(alias_name, alias_value);
			}
			else
			{
				char *alias = get_alias(alias_name);

				if (alias != NULL)
				{
					my_print(alias_name);
					my_print("='");
					my_print(alias);
					my_print("'\n");
				}
				else
				{
					my_print("alias: not found: ");
					my_print(alias_name);
					my_print("\n");
				}
			}
		}
		else
		{
			display_aliases();
		}
	}
}
