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

char **get_input();
char **get_path();
char *get_environ(char *envar);
char *pathtoexecute(char **input);
int execute(char **input);

void control_c(int c);
char *_strdup(char *str);
int _strlen(char *s);
int countstrings(char *str);
char *str_concat(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void freepptr(char **pptr);


#endif /* END HEADERSHELL */
