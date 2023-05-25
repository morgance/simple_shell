#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define READ_BUFF 1024
#define WRITE_BUFF 1024
#define FLUSH_BUFF -1
#define LOWER_CON 1
#define C_UNSIGHNED 2
#define CMD_NM 0
#define CMD_O 1
#define CMD_A 2
#define CMD_C 3
#define GETLINE_SH 0
#define STRTOK_SH 0
#define PST_FILE "shell_history"
#define FILE_PA 4096

extern char **environ;

/**
 * struct linkedlst - linled list
 * @ber:the number
 * @srt:path
 * @next:the next node pointer
 */
typedef struct linkedlst
{
	int ber;
	char *srt;
	struct linkedlst *next;
} link_s;
/**
 * struct datainfo - pseudo-arguments that will be passed into a function
 * @path:path for command
 * @str:string containing arguments
 * @argc:argument count
 * @argv:array of strings
 * @err_exits:error for exit
 * @err_count:count error
 * @_envi_:modified environ
 * @former_n:history node
 * @counter:line of input count
 * @filename:filename of the program
 * @alias:alias node
 * @status:status of the last command
 * @cmd_add:adress of pointer
 * @cmd_ty:cmd type
 * @read_in:read line input
 * @_env:linked list
 * @env_new:changed environ
 * @past_line:number line history
 */
typedef struct datainfo
{
	char *path;
	char filename;
	char **argv;
	char **_envi_;
	char **cmd_add;
	char *str;
	int cmd_ty;
	int env_new;
	int read_in;
	int counter;
	int argc;
	int err_exits;
	int status;
	int past_line;
	link_s *alias;
	link_s *former_n;
	link_s *_env;
	unsigned int err_count;
} data_s;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct built - builtin string
 * @comm:builtin command
 * @func:function
 */
typedef struct built
{
	char *comm;
	int (*func)(data_s *)
} built_t;
int _history(data_s *data);
int unset_alias(data_s *data, char *n);
int set_alias(data_s *data, char *n);
int print_alias_str(link_s *pro);
int alias_sh(data_s *data);
void data_info(data_s *data);
void set_data(data_s *data, char **ph);
void free_strct(data_s *data, int pst);
void _inputs(char strg);
int _charac(char n);
int _wrfd(char n, int filed);
int _prnt(char *stng, int filed);
char *memory_set(char *n, char nm, unsigned int i);
void free_sh(char **strng);
void *real_sh(void *dest, unsigned int old_ms, unsigned int new_ms);
int conv_str_int(char *n);
void print_msg(data_s *data, char strngs);
int print_deci(int input, int filed);
void remove_comms(char *addr);
char *_numcon(long int num, int base, int flags);
link_s *node_new(link_s **hd, const char *srt, int ber);
link_s *node_end(link_s **hd, const char *srt, int ber);
size_t print_str(const link_s *head);
int del_node(link_s **dest, unsigned int deleto);
void free_nodes(link_s **head);
size_t leng_ls(const link_s *head);
char **arry_strng(link_s *head);
size_t print_elem(const *head);
link_s *str_strts(link_s *head, const char pfix, char n);
ssize_t get_index(link_s *head, link_s *pnodes);
char *copy_str(char *prim, const char frm);
char *duplic_str(const char *strng);
void print_inp(const char *strng);
int _putchar(char c);
char **strtow(char *str, char *delimiters);
char **token(char *str, char delimiter);
int test_deli(data_s *data, char *chbf, size_t *ap);
void st_check(data_s *data, char *chbf, size_t leng, size_t aj, size_t *ap);
int alias_rep(data_s *data);
int vars_str(data_s *data);
int _string_rp(char **old_str, char *new_str);
int collective(data_s *data);
int _isalpha(int c);
int _atoi(char *s);
int is_lim(char c, char *lim);
void data_info(data_s *data);
void set_data(data_s *data, char **ph);
void free_strct(data_s *data, int pst);
int set_environment_variable(char **env, const char *name, const char *value);
int exit_handle(data_s *data);
int mkdir(data_s *data);
char *_strprint(char *dest, const char *src, int n);
char *_strcpy(char *dest, char *src, int n);
char **get_env(data_s *data);
int _getenv(data_s, *data, char *var, char *value);
int my_environ(data_s *data);
char *exits_env(data_s *data, const char *name);
int print_lists_env(data_s *data);
int _erase_env(data_s *data);
int hsh(data_s *data, char **argv);
int find_path(data_s *data);
void find_error(data_s *data);
int main(int argc, char **argv);
int bfree(void **ptr);
char *get_string_file(data_s *data);
int write_string(data_s *data);
int read_string(data_s *data);
int is_exec(data_s *data, char *path);
char *dupli_char(char *pstrn, int sindx, int spinx);
char *chk_path(data_s *data, char *pstrn, char *cmd);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, const char *src);
#endif
