-

![](https://camo.githubusercontent.com/df39b812688dc0ef3cd5c591489f9d0b7ae6db126c1ed3845f4bd3c7e957c139/68747470733a2f2f6173736574732e776562736974652d66696c65732e636f6d2f3631303533313536343461323666373739313261316164612f3631303534306538623463643639363937393466653637335f486f6c626572746f6e5f5363686f6f6c5f6c6f676f2d30342d30342e737667)

-
### Sinópsis

A shell provides an interface to the Unix system. It collects information and runs programs based on input. When a program finishes running, it displays the output of that program.

Shell is an environment in which we can run our commands, programs, and shell scripts. There are different flavors of shell, just like there are different flavors of operating systems. Each type of shell has its own set of recognized commands and functions.

### Description

This project is a simple version of the Linux Shell, it applies the basics and has limited functionality. It has been developed using the C programming language.


<hr>


### General considerations

- The program is built and runs on Ubuntu 14.04 LTS
- The program is compiled with gcc 4.8.4 using the -Wall -Werror -Wextra and -pedantic flags
- The code is in format: Betty style. betty *.c
- All headers are in header.h
- The program has no memory leaks in the parent process or in each child process.
- Simple_Shell has the same output as sh (/bin/sh), as well as the same error output.

### List of functions and system calls
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid `(man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror `(man 3 perror)
- `read `(man 2 read)
- `readdir` (man 3 readdir)
- `signal `(man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat `(__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait `(man 2 wait)
- `waitpid `(man 2 waitpid)
- `wait3 `(man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)


------------


### Compilation

simple_shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Tests

simple_shell should work like this in interactive mode:

```shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
also in non-interactive mode:
```shell
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

------------


### Authors
- [Agustin Espinoza](https://github.com/tinespinosaa "Agustin Espinoza")
- [Mauricio Carrasco](https://github.com/mauricodev "Mauricio Carrasco")
