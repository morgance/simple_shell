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
 * struct datainfo -




















#endif
