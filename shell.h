#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

extern char **environ;

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} ken_list_kt;

#define WRITE_BS 1024
#define BUF_KFL -1
#define K_USE_KGETLINE 0
#define K_USE_KSTRTOK 0
#define K_CMD_KOR		1
#define K_CMD_KAND		2
#define K_CMD_KNORM	0
#define K_CMD_KCHAIN	3
#define READ_KBS 1024

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

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
	ken_list_kt *env;
	ken_list_kt *history;
	ken_list_kt *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} k_info_kt;

typedef struct builtin
{
	char *type;
	int (*func)(k_info_kt *);
} k_builtin_ktable;

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
int k_replace_kvars(k_info_kt *);
int k_read_khistory(k_info_kt *info);
int _myexit(k_info_kt *);
int _mycd(k_info_kt *);
int _isalpha(int);
int f1(int, int);
int _atoi(char *);
int _myhelp(k_info_kt *);
ssize_t k_get_kinput(k_info_kt *);
int f2(int, int);
int _getline(k_info_kt *, char **, size_t *);
int _erratoi(char *);
void k_print_kerror(k_info_kt *, char *);
int f3(int, int);
void sigintHandler(int);
int k_build_khistory_klist(k_info_kt *info, char *buf, int linecount);
int k_renumber_khistory(k_info_kt *info);

int k_replace_kstring(char **, char *);
ken_list_kt *add_node(ken_list_kt **, const char *, int);
ken_list_kt *add_node_end(ken_list_kt **, const char *, int);
char *_getenv(k_info_kt *, const char *);
int f4(int, int);
int _myenv(k_info_kt *);
int _mysetenv(k_info_kt *);
int k_print_kd(int, int);
char *k_convert_knumber(long int, int, int);
int f5(int, int);
void k_remove_kcomments(char *);
int interactive(k_info_kt *);
int k_is_kdelim(char, char *);
int _myhistory(k_info_kt *);
int _myalias(k_info_kt *);
int k_is_kchain(k_info_kt *, char *, size_t *);
void k_check_kchain(k_info_kt *, char *, size_t *, size_t, size_t);
int k_replace_kalias(k_info_kt *);
size_t k_print_klist_kstr(const ken_list_kt *);
int delete_knode_at_kindex(ken_list_kt **, unsigned int);
void k_free_klist(ken_list_kt **);
void k_find_kcmd(k_info_kt *);
void k_fork_kcmd(k_info_kt *);
int _myunsetenv(k_info_kt *);
void k_free_kinfo(k_info_kt *, int);
int f6(int, int);
int populate_kenv_klist(k_info_kt *);
size_t k_list_klen(const ken_list_kt *);
char **ken_list_kto_strings(ken_list_kt *);
int good(int, int);
int hsh(k_info_kt *, char **);
int k_find_kbuiltin(k_info_kt *);
char **k_get_kenviron(k_info_kt *);
int really(int, int);
char *get_khistory_kfile(k_info_kt *info);
int k_write_khistory(k_info_kt *info);
void k_clear_kinfo(k_info_kt *);
char *k_starts_kwith(const char *, const char *);
char *_strchr(char *, char);
int matt(char, int);
char *_strcat(char *, char *);char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
void k_set_kinfo(k_info_kt *, char **);
size_t k_print_klist(const ken_list_kt *);
char great(int, char *);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int _strlen(char *);
int _strcmp(char *, char *);
ken_list_kt *node_kstarts_kwith(ken_list_kt *, char *, char);
ssize_t get_knode_kindex(ken_list_kt *, ken_list_kt *);
int _unsetenv(k_info_kt *, char *);
int _setenv(k_info_kt *, char *, char *);
char *_strncpy(char *, char *, int);
int bfree(void **);
char *_strncat(char *, char *, int);
char **strtow(char *, char *);
char **strtow2(char *, char);
int is_cmd(k_info_kt *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *dup_chars(char *, int, int);
void _eputs(char *);
int _eputchar(char);
void _puts(char *);
int _putchar(char);
char *k_find_kpath(k_info_kt *, char *, char *);
int loophsh(char **);

#endif
