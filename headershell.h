#ifndef HEADERSHELL_H_
#define HEADERSHELL_H_

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


char **get_input(char *line);
char **get_path(char **env);
char *get_environ(char *envar);



#endif
