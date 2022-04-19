#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;

/* Aux Functions */
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s, char *t, int n);
int _putchar(char c);
void _puts(char *str);
char *_itoa(int num, int base);
int _atoi(char *s);

/* Main functions */
void prompt(void);
char *get_input(int status);
int compare_builtins(char **ar, char **av, int cnt, int *status);
int compare_builtins_2(char **ar, char **av, int cnt, int *status);
int write_builtins(char **ar);
int validation(char **ar, char **paths, char **av, int cnt, int *status);
int child_process(char *first, char **ar, char **av, int cnt, int *status);
void continue_programm(int sig);

/* Helper functions */
char **tokenizer(char *str, char *delim);
int count_tokens(char *str, char *delim);
int only_special_characters(char *command);
void free_ar(char **ar);
char **foreach_concat(char **ar, char *src);
int is_valid_number(char *str);

/* Environment variables */
char *get_paths_of_env_var(char *env);
char **get_PATHS(void);

/* Helper built-ins */
char *_getenv(char *var_env);
char *getenv_content(char *var_env, char *line_env);
int index_var_env(char *var_env);
ssize_t read_textfile(const char *filename, size_t letters);
char *find_var_env(char *var_env);
int write_dollar_symbol(char *token, int status);

/* Built-in cd functions */
int cmp_cd_only(char *str);
int cmp_cd_dash(char *str);
int go_to_dir(char *directory);
char *go_to_home_directory(void);
char *get_oldpwd(void);

/* Built-ins */
void fprintenv(char **env);
int write_exit(char **ar, int *status);
int write_env(char **ar);
int write_setenv(char **ar, char **av, int cnt, int *status);
int write_unsetenv(char **ar, char **av, int cnt, int *status);
int write_cd(char **ar, char **av, int cnt);
int write_help(char **ar, char **av);
int write_help_command(char *command);
int compare_dollar(char **ar, int status);

/* Handle Errors */
int print_error(char *programm, int count, char *command);
int not_found(char *programm, int count, char *command);
int ext_err(char *programm, int count, char **ar);
int error_unsetenv(char *programm, int count, char **ar);
int error_set_unset_env(char *programm, int count, char **ar);
int error_cd(char *programm, int count, char **ar);
int help_not_found(char *programm, char **ar);

/* Developing */
char *create_new_var_env(char *var_env, char *var_content);
char **new_environ_with_new_var(char *new_var);
int _setenv(char **ar);
int _unsetenv(char **ar);

/* Temporal */
void print_ar(char **ar);

#endif
