#ifndef ALIAS_H
#define ALIAS_H

#define MAX_ALIASES 100
typedef struct
{
	char *name;
	char *value;
} Alias;
Alias aliases[MAX_ALIASES];
extern int num_aliases;
int num_aliases = 0;

#endif /* ALIAS_H */
