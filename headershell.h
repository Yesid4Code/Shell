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


char **get_input();
char **get_path();
char *get_environ(char *envar);
char *pathtoexecute(char **input);
void execute(char **binpath);

char *_strdup(char *str);
int countstrings(char *str);

#endif
