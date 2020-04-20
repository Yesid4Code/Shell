#ifndef HEADERSHELL_H_
#define HEADERSHELL_H_

#define _GNU_SOURCE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

char *printpromt();
char **get_input(char *line);
char *get_path(char *input);
char *get_environ(char *envar);
char *pathtoexecute(char **input);
int execute(char *argv, char *fullpath, char **input,
	    char **env, unsigned int countexec);

void control_c(int c);
char *_strdup(char *str);
int _strlen(char *s);
int countstrings(char *str);
char *str_concat(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void freepptr(char **pptr);
void *_calloc(unsigned int sizepptr, unsigned int sizetype);
char *_copy(char *dest, char *src);
char *_memset(char *str, char a, unsigned int size);

#endif /* END HEADERSHELL */
