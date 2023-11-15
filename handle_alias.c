#include "shell.h"
/**
 * handle_alias - Handle alias related operations.
 * @input: The input command.
 */
void handle_alias(const char *args[])
{
	const char *alias_name = args[1];

	if (alias_name != NULL)
	{
		const char *alias_value = args[2];

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
	} else {
		display_aliases();
	}
}
