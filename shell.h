#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

void set_alias(const char *name, const char *value);
char *get_alias(const char *name);
void display_aliases(void);
void clear_aliases(void);
void handle_alias(const char *args[]);

void remove_comments(char *input);

int replace_variables(char *input);

extern char **environ;

void mydisplay_prompt(const char *prompt_name);
void my_print(const char *string);
void read_command(char *input, size_t size);
void execute_command(const char *input);
void env_shell(void);
int setenv_shell(char **args);
int unsetenv_shell(char **args);
void cd_shell(char *path);
int change_dir(char *path);
int handle_builtin(char **args);
int handle_setenv(char **args);
int handle_unsetenv(char **args);

char *current_dir();
int log_operator(char **commands, int num_commands);
char *read_file(FILE *file);
int execute_single_command(char *command);

#endif /* SHELL_H */
