#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

/* Aux Functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s, char *t, int n);
int _putchar(char c);
void _puts(char *str);

/* Main functions */
void prompt(void);
char *get_input(void);
char **split_string(char *str, char *delim);

/* Helper functions */
int write_exit(char *command);
int write_spaces(char *command);
int write_env(char **ar);
int count_subcommands(char *str);
void free_ar(char **ar);
char **tokalloc(char *buffer, char *delim, int ctok);
char **_strtok_all(char *buffer, char *delimiter);

/* PATH */
char *getenv_PATH(void);
char **get_PATHS(void);
void add_backslash(char **paths);

/* Execution functions*/
int execute_basic_command(char **ar);

/* Built-ins */
void fprintenv(char **env);

/* Debug */
void debug(char *line, char **ar);

#endif
