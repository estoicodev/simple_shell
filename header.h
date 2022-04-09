#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * struct argvs - Define a structre for argvs in programm execution
 *
 * @first: First argument in the programm execution
 */
typedef struct argvs
{
	char *first;
} av;

/**
 * struct token - Define a structre for tokens in the line command
 *
 * @first: First token in the line command
 * @second: Second token in the line command
 */
typedef struct token
{
	char *first;
	char *second;
} tok;

/* Structure functions */
void init_tok(struct token *tk, char *first, char *second);
void init_argvs(struct argvs *av, char *first);

/* Aux Functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* Main functions */
char *get_cmd();
char **split_string(char *str);
int execution (char **ar);

/* Helper functions */
int write_exit(char *command);
int write_eof(char *command);
void last_newline_to_null(char *command);
int count_subcommands(char *str);
void free_ar(char **ar);

/* Execution functions*/
int execute_basic_command(char **ar);

/* Errors */
char *error_interactive(struct argvs *av, struct token *tk);

/* Debug */
void debug(char *line, char **ar);

#endif
