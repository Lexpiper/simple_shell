#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define BUFFSIZE 64
#define DELIMITER " \t\r\n\a"
#define _GNU_SOURCE

/*LIBRARIES*/
#include <ctype.h>
#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/*global environment variable */
extern char **environ;

int execute_file_program(char **args);
int search_dir(char **directories, char **args);
int run_command(char **arg_list);
int handle_builtin(char **args, char *buffer, int loops);

/* String Handlers */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);

/* Path & Search Handlers */
char *append_path(char *path, char *cmd);
char *_get_env_var(char *name);
int get_path_file(char **args);

/* Built-ins Functions */
int ss_exit(char **args, char *buffer, int loops);
void print_env(void);
void ss_cd(char **args);

/* Simple Shell Handlers */
void ss_sighandle(int sign);
void _free(int n, ...);
void print_errmsg(char **executable, char **args, int count);
int count_input_args(char *input);
void print_number(int n);
void print_number(int n);
int is_number(char *str);
char **tokenize_input(char *input);
int _atoi(char *s);

#endif /* SIMPLE_SHELL_H */

