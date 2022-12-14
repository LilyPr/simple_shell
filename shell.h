#ifndef _SHELL_H_
#define _SHELL_H_

/**###### environ var ######*/

extern char **environ;

/**##### MACROS ######*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**###### LIBS USED ######*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/**###### STRING FUNCTION ######*/

char *_strtok(char *str, const char *tok);
unsigned int delim_checker(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void rev_array(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/**###### MEMORIE  MANGMENT ####*/

void free_env(char **env);
void *fill_array(void *arr int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int nw_size);
void free_all(char **input, char *line);

/**###### INPUT Function ######*/

void prompt(void);
void sign_handle(int sig);
char *_getline(void);

/** ###### Command parser and extractor ###*/

int path_check(char **line);
char *_getenv(char *name);
char **parse_handle(char *cmd);
int handle_builtin(char **cmd, int er);
void file_read(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void set_env(char **envi);
int check_command(char **token, char *line, int count, char **argv);
void file_create(char *line, int count, FILE *fd, char **argv);
void exit_builtfile(char **cmd, char *line, FILE *fd);

/** ####BUL FUNC #####*/

void hashtag_handle(char *buff);
int history(char *input);
int check_his(char **cmd, int er);
int show_env(char **cmd, int er);
int current_dir(char **cmd, int er);
int check_help(char **cmd, int er);
int echo_built(char **cmd, int er);
void exit_builtin(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** ####error handle and Printer ####*/
void print_number(unsigned int n);
void print_numbers(int n);
void print_error(char *line, int c, char **argv);
void pr_error(char **argv, int c, char **cmd);


/**
 * struct builtin - contain bultin to handle and function to excute
 * @code:pointer to char
 * @home:home to excute when bultin true
 */

typedef struct  builtin
{
	char *code;
	int (*home)(char **line, int er);
} builtin_t;

#endif
