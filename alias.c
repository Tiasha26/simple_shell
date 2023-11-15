#include "shell.h"
#include "alias.h"
/**
 * set_alias -  Set an alias.
 * @name: The alias name.
 * @value: The alias value.
 */
void set_alias(const char *name, const char *value)
{
	if (num_aliases < MAX_ALIASES)
	{
		aliases[num_aliases].name = strdup(name);
		aliases[num_aliases].value = strdup(value);
		num_aliases++;
	}
	else
	{
		my_print("Alias limit exceeded. Cannot set alias.\n");
	}
}

/**
 * get_alias -  Get the value of an alias by its name.
 * @name: The alias name to look up.
 * Return: The alias value if found, or NULL if not found.
 */
char *get_alias(const char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(name, aliases[i].name) == 0)
		{
			return (aliases[i].value);
		}
	}
	return (NULL);
}

/**
 * display_aliases -  Display all defined aliases.
 */
void display_aliases(void)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		my_print(aliases[i].name);
		my_print("='");
		my_print(aliases[i].value);
		my_print("'\n");
	}
}

/**
 * clear_aliases - all defined aliases and free memory.
 */
void clear_aliases(void)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		free(aliases[i].name);
		free(aliases[i].value);
	}
	num_aliases = 0;
}
