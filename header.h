#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/* Aux Functions */
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s, char *t, int n);
int _putchar(char c);
void _puts(char *str);
char *_itoa(int num, int base);

/* Main functions */
void prompt(void);
char *get_input(void);
int compare_builtins(char **ar);
int validation(char **ar, char **paths, char **av, int cnt);
int handle_child_process(char **ar, char **av, int cnt);

/* Helper functions */
char **tokenizer(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **tokalloc(char *buffer, char *delim, int ctok);
char **_strtok_all(char *buffer, char *delimiter);
int write_exit(char **ar);
int only_spaces(char *command);
char *start_spaces(char *command);
int write_env(char **ar);
int count_subcommands(char *str);
void free_ar(char **ar);
void print_ar(char **ar);
char **foreach_concat(char **ar, char *src);

/* PATH */
char *_getenv(char *env);
char **get_PATHS(void);

/* Built-ins */
void fprintenv(char **env);

/* Handle Errors */
int print_error(char *programm, int count, char *command);

#endif
