#ifndef HEADERSHELL_H_
#define HEADERSHELL_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


char **get_input(char *line, int read);
char **get_path();
char *get_environ(char *envar);
void execute(char **binpath);
char *_strdup(char *str);

#endif
