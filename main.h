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
#include <signal.h>

extern char **environ;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *s);
char *_getenv(char *name);
void resize_buf(char **buffer, ssize_t *r_bytes, ssize_t len, FILE *stream);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp_(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _setenv_(char *var_name, char *new_value, int flag);
void handle_error(char *path);
int environ_size(char **env);
char *concat(char *var_name, char *new_value);
void _chdir(char **path);
char *check_path(char **path, char *old_path, char *new_old, char *name_var);
void update_pwd(char *old_path, char *new_path);
void free_paths(char *old_path, char *new_path, char **path);
void handle_error(char *path);
int _setenv(char *var_name, char *new_value, int flag);
int _strcmp(char *s1, char *s2, int len);
char *_strtok(char str[], char *delims);
void prompt(char **buf, ssize_t fd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void exe(char *arg0, char **args, char **env);
char **split_str(char *str, char *tok);
void _free(char **cmd);
void print_env(char **env);
char *allocate(char c, int size);
void run_fork(char **command, char **av, char **env);
void exit_p(char **command);
void check_echo(char **command, pid_t child, char *arg0);
char *handle_command(char **command);
void free_exit(char **command, int is_arr);
void ctrl_c(int signals);
void print_error(char **av, char **command, char *arg0);

#endif /* #ifdef MAIN_H */

