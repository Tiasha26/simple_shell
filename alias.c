#include "shell.h"
#include "alias.h"
/**
 * @brief Set an alias.
 * @param name The alias name.
 * @param value The alias value.
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
 * @brief Get the value of an alias by its name.
 * @param name The alias name to look up.
 * @return The alias value if found, or NULL if not found.
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
 * @brief Display all defined aliases.
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
 * @brief all defined aliases and free memory.
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
