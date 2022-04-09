<h1 align="center" dir="auto"><a id="" class="anchor" aria-hidden="true" href="#"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>
<a target="_blank" rel="noopener noreferrer" href="https://camo.githubusercontent.com/df39b812688dc0ef3cd5c591489f9d0b7ae6db126c1ed3845f4bd3c7e957c139/68747470733a2f2f6173736574732e776562736974652d66696c65732e636f6d2f3631303533313536343461323666373739313261316164612f3631303534306538623463643639363937393466653637335f486f6c626572746f6e5f5363686f6f6c5f6c6f676f2d30342d30342e737667"><img src="https://camo.githubusercontent.com/df39b812688dc0ef3cd5c591489f9d0b7ae6db126c1ed3845f4bd3c7e957c139/68747470733a2f2f6173736574732e776562736974652d66696c65732e636f6d2f3631303533313536343461323666373739313261316164612f3631303534306538623463643639363937393466653637335f486f6c626572746f6e5f5363686f6f6c5f6c6f676f2d30342d30342e737667" height="75%" width="65%" data-canonical-src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" style="max-width: 100%;"></a>
</h1>

### Sinópsis

A shell provides an interface to the Unix system. It collects information and runs programs based on input. When a program finishes running, it displays the output of that program.

Shell is an environment in which we can run our commands, programs, and shell scripts. There are different flavors of shell, just like there are different flavors of operating systems. Each type of shell has its own set of recognized commands and functions.

### Description

This project is a simple version of the Linux Shell, it applies the basics and has limited functionality. It has been developed using the C programming language.





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


### Authors
- [Agustin Espinoza](https://github.com/tinespinosaa "Agustin Espinoza")
- [Mauricio Carrasco](https://github.com/mauricodev "Mauricio Carrasco")
