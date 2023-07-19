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

/* read/write buffer */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* convert_number() */
#define CONVERT_UNSIGNED
#define CONVERT_LOWERCASE

/* command chaining */
#define CMD_NORM     0
#define CMD_OR       1
#define CMD_AND      2
#define CMD_CHAIN    3

#endif
