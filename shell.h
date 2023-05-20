#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*Macros*/


/*Libraries*/
#include <ctype.h>
#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Prototypes*/
void _free(int n, ...);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char **tokenize_input(charrr *input);
int count_input_args(char *input);
void print_errmsg(char **executable, char **args, int count);
void print_number(int n);
int is_number(char *str);
int ss_exit(char **args, char *buffer, int loops);


#endif

