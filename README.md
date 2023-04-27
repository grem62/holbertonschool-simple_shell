# Simple shell :computer:







![](https://cdn.educba.com/academy/wp-content/uploads/2020/01/Bash-Shell-in-Linux.jpg)




## Description :newspaper:

The shell is a program that receives computer commands given by a user from his keyboard and sends them to the operating system, which will then execute them.

In the early days of computing, the shell was the only user interface available on a Unix-like system such as Linux. Nowadays and with the arrival of the mouse, all computers use graphical user interfaces (GUI) such as macOS or Windows 10, in addition to command line interfaces (CLI) such as the shell.
Here we have coded a simple shell that was asked in the holberton school curriculum.


# Authorized function ☑️:

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* printf (man 3 printf)
* fprintf (man 3 fprintf)
* vfprintf (man 3 vfprintf)
* sprintf (man 3 sprintf)
* putchar (man 3 putchar)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)


## Flowchart

![](https://i.imgur.com/WcN0ccr.jpg)

`Prompt`: A common implementation of this feature is to present the user with a command prompt to solicit their participation

`Get line`: The purpose of this function is to capture a line of user input and convert it into a string format for further processing

`Split line`: The goal of this function is to separate the first string being the command thanks to a delimiter to be able to read the next string which will be an option of this command 

`Exec command`: The main purpose of this function is to determine whether the current process has permission to access a specific file or directory. Two parameters must be passed to it: the name of the file and the access mode to be checked (read, write or execute).

`Free memory`: The free function allows to free the memory and avoid memory leaks


***
## Compilator :space_invader:

~~~c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
~~~

***
## Testing :arrow_forward:

The shell should work like this in interactive mode:

~~~c
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
~~~
But also in non-interactive mode

~~~c
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
~~~
***

# basic command simple shell:

pwd: The pwd command means to print the working directory. It is one of the most basic and frequently used commands in Linux

cd:  Displays the name of the current directory or changes the current directory. If used with a drive letter only (for example, cd C:), cd displays the name of the active directory in the specified drive. If used without parameters, cd displays the active drive and directory

ls: Ls is one of the basic commands that every Linux user should know. The ls command lists the files and directories in the file system and displays detailed information about them

echo: The echo command in Linux is used to display the line of text/strings that is passed as an argument

# Author project



- [@Mickael Tartar](https://github.com/mickaeltartar)

![](https://ca.slack-edge.com/T0423U1MW21-U04MN5Q25MZ-595df4c1f6ed-192)




- [@Lenne Sebastien](https://github.com/sebounti)

![](https://ca.slack-edge.com/T0423U1MW21-U04NA9QLEHE-8ff8d95c43cf-192)





- [@Gremont Matheo](https://github.com/grem62)

![](https://ca.slack-edge.com/T0423U1MW21-U04NC00H4JU-adedd0d861f8-192)
