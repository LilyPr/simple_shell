#ifndef SHELL_H
#define SHELL_H
#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "signal.h"
extern char **environ;

/**
 * struct path - linked list of environment variables
 * @ptr: pointer to environment variable string
 * @next: points to next node in linked list
 */
typedef struct path
{
	char *ptr;
	struct path *next;
} path_t;

/* entry point */
int main(int argc, char **argv);

/* input */
void rock(char *coral);
char *_readline(void);
char **bridge_line(char *buffer, char *del);
int _executes(char **args, char *colar);

/* path functions */
path_t *generate_pth(void);
char *check_pth(path_t *head, char *input);
char *path_conc(char *s1, char *s2);

/* built in functions*/
int built_func(char **args, char *input);
void shell_exit(char **args, char *input);
void print_enviornment(void);

/* enviornment funcitons */
path_t *_env(void);
char *find_enve(char *var);
int match_enve(char *input);
void _enve(char *str, char *value);

/* string tokenize functions*/
int pass(char k, const char *delimeter);
char *_strtok(char *input, const char *delimeter);
char **bridge_line(char *buffer, char *delimeter);
int count_wrd(char *str);

/* execution */
int _exec(char **args, char *rock);
int _execute(char **args, char *coral);

/* functions that free */
void free_path(path_t *head);
void free_enve(path_t *head);

/* string functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_itoa(int num);
int _numberlen(int n);
char *_strcpysource(char *dest, char *src, int n);
void _puts(char *str);
/* variables */
path_t *_paths;
path_t *environment;
int line_count;
void *_realloc(void *ptr, unsigned int before, unsigned int after);
void errenous(char **args, char *cmd, int errno);
void sign_handle(int sign_handle);
/*ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
int find_match(const char *s1, char *s2);
#endif
