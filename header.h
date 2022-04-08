#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/* Aux Functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

int write_exit(char *command);
void last_newline_to_null(char *command);
int count_subcommands(char *str);
char **split_string(char *str);
int execute_basic_command(char *command);

#endif
