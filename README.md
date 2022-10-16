# 0x16. C - Simple Shell
A simple UNIX command interpreter an implementation of the original UNIX shell in C.

### Invocation :running:

Usage: **shell** [filename]

To invoke **shell**, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o shell
./shellby
```

**Shellby** can be invoked both interactively and non-interactively. If **shellby** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'hello'" | ./shell
'hello'
$
```

## :running: Getting Started

* [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/) - Operating system reqd.

* [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/) - Compiler used


## :warning: Prerequisites

* Must have `git` installed

* Must have repository cloned

```
$ sudo apt-get install git
```


## :arrow_down: Installing

Clone the repository into a new directory

```
$ git clone https://github.com/BennettDixon/simple_shell.git
```
Compile with the following:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o seashell
```

## Authors :black_nib:

* Moses MWangi <[mosessofteng](https://github.com/mosessofteng)>
* Fiona Mbogo <[Ficharagu](https://github.com/Ficharagu)>






