<img src="Simple_Shell_Project.png" width="100%" height="200">

A Unix Shell is a programam named command-line interpreter that provides a command line user interface for Unix-like operating systems that users employ to type commands. <a href="https://en.wikipedia.org/wiki/Unix_shell">Wikipedia</a>


The goal of the "Simple Shell Project" is to learn how to build a simpler version of a "command-line interpreter" (Unix shell) using the programming language "C".
## Compilation
When the program is compiled, it will functions as the shell terminal. To compile, you can use gcc -Wall -Werror -Wextra -pedantic *.c

## Testing
The shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Project Restrictions.
For this project, only the following functions functions and system calls were allowed:
|Functions and system calls allowed|
|----|----|----|
|access (man 2 access)|chdir (man 2 chdir)|close man 2 close|

:computer::closed_lock_with_key:
- access (man 2 access)
- chdir (man 2 chdir)