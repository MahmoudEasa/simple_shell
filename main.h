#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct list_s - struct for saving strings
 * @string: pointer to string
 * @next: pointer to next node
 * 
 * Description: struct for saving strings
*/

typedef struct list_s
{
	char *string;
	struct list_s *next;
} list_t;

char *_strtok(char str[], const char *delims);
void add_str(list_t **head, const char*str);
char *get_next_node(list_t **current_node);
void prompt(char **buf);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void exe(char **args, char **env);
char **split_str(char *str);
void _free(char **cmd);
void print_env(char **env);
char *allocate(char c, int size);
void run_fork(char **command, char **av, char **env);
void exit_p(char **command);
void print_pid();
void print_ppid();
void check_echo(char **command, pid_t child);
void handle_command(char **command, char (*arg0)[30]);
void free_exit(char **command, int is_arr);

#endif /* #ifdef MAIN_H */

