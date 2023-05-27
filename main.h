#ifndef _SHELL_H_
#define _SHELL_H_
extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

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

char *_strtok(char *str, const char *tok);
unsigned int _check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
void free_env(char **env);
void *fill_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free(char **input, char *line);
void prompt(void);
void ctrl_c(int sig);
char *_getline(void);
int path_cmd(char **line);
char *_getenv(char *name);
char **split_str(char *cmd);
int handle_buil(char **cmd, int er);
void _read_file(char *filename, char **argv);
char *build_cmd(char *token, char *value);
int check_buil(char **cmd);
void add_envi(char **envi);
int exe_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);
void hashtag_handle(char *buff);
int his_dis(char **cmd, int er);
int print_env(char **cmd, int er);
int _chdir(char **cmd, int er);
int print_help(char **cmd, int er);
int handle_echo(char **cmd, int er);
void exit_p(char **cmd, char *input, char **argv, int c);
int _print_echo(char **cmd);
void print_num(unsigned int num);
void print_num_int(int num);
void err_print(char *line, int count, char **av);
void _perror(char **argv, int c, char **cmd);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
