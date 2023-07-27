#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

#define CONVERT_UNSIGNED 2
#define CONVERT_LOWERCASE 1

#define CMD_NORM     0
#define CMD_OR       1
#define CMD_AND      2
#define CMD_CHAIN    3

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()
 * @linecount_flag: counts line of input
 * @fname: file name of the program
 * @env: linked list environ
 * @environ: copy of env
 * @history: history node
 * @alias: alias node
 * @env_changed: environment change varaible
 * @status: status of last commmand
 * @cmd_buf: pointer to cmd_buf
 * @cmd_buf_type: Command buffer type
 * @readfd: file descriptor to read from
 * @history_count: history line count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int history_count;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, \
		0, 0}

/**
 * struct builtin - built in string & function
 * @type: command flag
 * @func: function
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} builtin_table;

/* getenv.c */
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

/* environ.c */
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

/* errors.c */
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* memory.c */
int bfree(void **ptr);


char **list_to_strings(list_t *);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char*, char);

/* shell.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* errors1.c */
char *convert_number(long int num, int base, int flags);
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
void remove_comments(char *buf);

/* _strtow.c */
char **strtow(char *str, char *d);

/* vars.c */
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char*new);

/* realloc.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);

/* history.c */
int read_history(info_t *shell_info);
int write_history(info_t *shell_info);
int history_builder(info_t *shell_info, char *buffer, int lcount);
char *get_history_file(info_t *shell_info);
int renumber_history(info_t *shell_info);

/* _atoi.c */
int _atoi(char *s);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);

/* getinfo.c */
void set_info(info_t *info, char **av);
void clear_info(info_t *info);
void free_info(info_t *info, int all);

/* getline.c */
int _getline(info_t *info, char **lineptr, size_t *length);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
void sigintHandler(int);
ssize_t get_input(info_t *info);

/* parse.c */
char *find_path(info_t *info, char *pathstr, char *cmd);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);

/* builtin.c */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* builtin1.c */
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
#endif
