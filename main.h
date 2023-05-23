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
 * @ber:thue number 
 * @srt:path
 * @next:the next node pointer
 */
typedef struct linkedlst
{
	int ber;
	char *srt;
	struct linkedlst *next;
}link_s;

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
 * @alia:alias node
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
	link_s *alias;
	link_s *former_n;
	link_s *_env;
	unsigned int err_count;
}data_s;
/**
 * struct built - builtin string
 * @comm:builtin command
 * @func:function
 */
typedef struct built
{
	char *comm;
	int (*func)(data_s *)
}built_t;














#endif
