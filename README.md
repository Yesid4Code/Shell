<img src="Simple_Shell_Project.png" width="100%" height="200">

A **Unix Shell** is a programam named **command-line interpreter** that provides a command line user interface for Unix-like operating systems that users employ to type commands. <a href="https://en.wikipedia.org/wiki/Unix_shell">Wikipedia</a>


The goal of the **"Simple Shell Project"** is to learn how to **build** a simpler version of a "command-line interpreter" (Unix shell) using the programming language **"C"**.

## Compilation
When the program is compiled, it will functions as the shell terminal. To compile, you can use gcc -Wall -Werror -Wextra -pedantic *.c

## Testing
The **shell** should work like this in interactive mode:
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

|Functions|Funtions|Functions|
|---------|--------|----------|
|access (man 2 access)|getcwd (man 3 getcwd)|signal (man 2 signal)|
|chdir (man 2 chdir) |getline (man 3 getline)|stat (__xstat) (man 2 stat)|
|close (man 2 close)|isatty (man 3 isatty)|lstat (__lxstat) (man 2 lstat)|
|closedir (man 3 closedir)|kill (man 2 kill)|fstat (__fxtat) (man 2 fstat)|
|execve (man 2 execve)|malloc (man 3 malloc)|strtok (man 3 strtok)|
|exit (man 3 exit)|open (man 2 open)|wait (man 2 wait)|
|_exit (man 2 _exit)|opendir (man 3 opendir)|waitpid (man 2 waitpid)|
|fflush (man3 fflush)|perror (man 3 perror)|wait3 (man 2 wait3)|
|fork (man 2 fork)|read (man 2 read)|wait4 (man 2 wait4)|
|free (man 3 free)|readdir (man 3 readdir)|write (man 2 write)|

## [Simple Shell Flowchart](https://drive.google.com/file/d/1vYaFTEbbCWvO0TYoXHQDRIeT5kWX9bOW/view?usp=sharing)

## :busts_in_silhouette: Contributors

### :bust_in_silhouette: Yesid A. López V.
* Twitter: <a href="https://twitter.com/Yesid4Code">@Yesid4Code</a>
* Github:  [@Yesid4Code](https://github.com/Yesid4Code)

### :bust_in_silhouette: Crispthofer A. Rincon M.
* Twitter: [@CrispthoAlex](https://twitter.com/CrispthoAlex)
* Github:  <a href="https://github.com/CrispthoAlex">@CrispthoAlex</a>