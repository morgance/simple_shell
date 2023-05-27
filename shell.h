#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

#define KEN_WRITE_BS 1024
#define KEN_BUF_F -1

#define KEN_COMMAND_N	0
#define CMD_OR		1

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} ken_listk_t;

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
	ken_listk_t *env;
	ken_listk_t *history;
	ken_listk_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
#define CONV_LOW	1
#define CONV_UNS	2
#define KEN_READ_BS 1024
#define CMD_AND		2
#define CMD_CHAIN	3
#define USE_GETL 0
#define USE_STRT 0
#define INF_INT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

int hsh(info_t *, char **);
int f2(int, int);
int find_bltin(info_t *);
void *_realloc(void *, unsigned int, unsigned int);
void fnd_comand(info_t *);
void forkk_commd(info_t *);
int f3(int, int);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char **strtow(char *, char *);
int f4(int, int);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
int f5(int, int);
int _strlen(char *);
int _strcmp(char *, char *);
int f6(int, int);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
char *ken_get_khistory_file(info_t *info);
int f7(int, int);
int ken_write_khistory(info_t *info);
int ken_read_khistory(info_t *info);
int f8(int, int);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

int is_cmd(info_t *, char *);
char *dupl_ch(char *, int, int);
char *find_path(info_t *, char *, char *);

void _eputs(char *);
int _epucha(char);
int f1(int, int);
int ken_ptfd(char c, int fd);
int ken_psfd(char *str, int fd);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
int f9(int, int);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
ken_listk_t *add_node(ken_listk_t **, const char *, int);
ken_listk_t *add_node_end(ken_listk_t **, const char *, int);
int f10(int, int);
size_t ken_print_klist_str(const ken_listk_t *);
int ken_delete_knode_at_index(ken_listk_t **, unsigned int);
void free_list(ken_listk_t **);

int ken_eratoi(char *);
void print_error(info_t *, char *);
int f11(int, int);
int print_d(int, int);
char *conv_numb(long int, int, int);
void rem_comments(char *);
size_t list_len(const ken_listk_t *);
int f12(int, int);


char **ken_listk_to_strings(ken_listk_t *);
size_t print_list(const ken_listk_t *);
ken_listk_t *node_starts_with(ken_listk_t *, char *, char);
int f3(int, int);
ssize_t get_node_index(ken_listk_t *, ken_listk_t *);
int _myhistory(info_t *);
int ken_build_khistory_list(info_t *info, char *buf, int linecount);
int f14(int, int);
int ken_renumber_khistory(info_t *info);
int _myalias(info_t *);
void clr_info(info_t *);
int interactive(info_t *);
int ken_is_dlm(char, char *);
int f5(int, int);
int _isalpha(int);
int _atoi(char *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int f6(int, int);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int pop_envlist(info_t *);
int f7(int, int);
int bfree(void **);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void signintHand(int);
char **ken_get_envron(info_t *);
int ken__unsektenv(info_t *, char *);
int ken__setkenv(info_t *, char *, char *);

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} bltin_tab;


int replace_vars(info_t *);
int replace_string(char **, char *);

extern char **environ;
int f8(int, int);
int shelloop(char **);
char *_strchr(char *, char);

#endif
