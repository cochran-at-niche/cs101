# Lesson 1: Life In The Shell 

```
               __
    .,-;-;-,. /'_\
  _/_/_/_|_\_\) /
'-<_><_><_><_>=/\
  `/_/====/_/-'\_\
   ""     ""    ""
```

## Outline

- What is a shell?
    - A special kind of program
    - "In computing, a shell is a user interface for access to an operating
      system's services." - [Wikipedia](https://en.wikipedia.org/wiki/Shell_(computing))
        - Operating system services include:
            - Users And Groups (i.e. permissions)
            - File Management and I/O
            - Memory Management
            - Process Management
            - Scheduling
            - Threading
            - Time
            - Network I/O (i.e. sockets)
            - Interprocess Communication (e.g. signals, pipes)
        - [The Linux Programming Interface](https://github.com/shihyu/Linux_Programming/blob/master/books/The%20Linux%20Programming%20Interface%20-%20A%20Linux%20and%20UNIX%20System%20Programming%20Handbook.pdf)
    - REPL (Read Evaluate Print Loop)
        - Other examples:
            - python
            - node
            - psql
            - bc
            - other scripting/interpreted languages
    - Examples
        - sh (Bourne shell)
        - csh (C shell)
        - ksh (Korn shell)
        - **bash** (Bourne Again Shell)
        - zsh (Z shell)
        - fish (Friendly Interactive Shell)
        - ash (Almquist Shell)
        - dash (Debian Almquist Shell)
- What is a program?
    - The word "program" is vague
        - Source vs compiled 
        - Compiled vs interpreted
    - Fundamentally, a set of instructions
        - Compiled
            - Human readable source code
            - Compiled to binary
            - Run directly as machine code
        - Interpreted
            - Human readable scripts
            - Input to other programs (e.g. `python my_script.py`)
            - Shebang (`#!/bin/bash`)
    - Data
        - Von Neumann architecture
            - Code/instructions _are_ data
        - `which`
            - Searches `$PATH`
            - `which bash`
            - `which which` :mindblown:
            - `which cd` :thinking:
- What is a process?
    - An instance of an executing program
        - Process ID (PID)
        - Real and Effective User and Group IDs (permissions)
        - Current working directory
        - Environment list
        - Allocated memory
            - Text (instructions)
            - Data (constants)
            - Heap (explicitly allocated)
            - Stack (function calls)
        - Open file descriptors (input/output)
            - standard:
                - stdin (0)
                - stdout (1)
                - stderr (2)
            - files
            - sockets
            - pipes
    - `ps aux`
    - /proc
- Anatomy of a shell command
    - Program name
        - In `$PATH`
    - Arguments
    - Options
    - Flags
    - Help
        - `--help`
        - `man` (i.e. "manual")
            - `man which`
            - `man man` :mindblown:
            - `man cd` :thinking:
    - Stdin, Stdout, Stderr
- Composing commands
    - `;`
    - `&&`
    - `||`
    - `$()` (or backticks)
    - Redirection
        - `<` - redirect file to stdin
        - `>` - redirect stdout to file (truncate it first)
        - `>>` - redirect stdout to file (append to it)
        - `2>&1` - redirect stderr to stdin
        - `&>` - redirect both stdout and stderr to a file
        - `<<< ''` - "Herestring" - redirect string literal to stdin
        - `<< END ...\n END` - "Heredoc" - redirect input stream literal to stdin
        - `<$()` - Treat output of command as a file
        - /dev/null - a useful black hole
    - Pipes and pipelines
        - `|` - use one process's stdout as the next process's stdin
- Navigation
    - `pwd`
    - `ls`
        - `ls -a`
        - `ls -l`
        - `ls -lh`
        - `ls -R`
    - `tree`
    - `cd`
        - `cd`
        - `cd ~`
        - `cd ~user`
        - `cd ..`
        - `cd -`
        - `cd /`
        - `$CDPATH`
    - `dirs`
        - `pushd`
        - `pop`
    - symlinks
        - `ln -s`
    - `alias`
    - `grep`
- History
    - `history`
    - `history 5`
    - Settings
        - `shopt -s histappend` - Only append to history file
        - `export HISTFILESIZE=10000`
        - `export HISTSIZE=10000
    - Arrow keys
    - `!!` - last command
        - e.g. `sudo !!`
    - `!*` - all args of last command
    - `!$` - last arg of last command
    - `ctrl-r` - search
- Job control
    - Signals
        - `ctrl-c` - SIGINT
        - `ctrl-z` - SIGTSTP
            - `bg`
            - `fg`
        - `ctrl-d` - End of file (EOF)
    - `&` - run in background
    - `jobs`
    - `kill`
    - `kill -9`
    - `kill $(jobs -p)`
    - `pkill`
    - `killall`
    - `$$` - PID
    - `$?` - Last error code
- Environment variables
    - Built-in:
        - `$USER`
        - `$PATH`
        - `$CDPATH`
        - `$TERM`
        - `$RANDOM`
        - `$SECONDS`
        - `$LINENO`
    - Inline (e.g. `VAR=whatever bash -c 'echo "$VAR"'`)
    - `export`
    - in .bashrc
- `.bashrc`
    - Interactive non-login shells
        - `.profile` and `.bash_profile` are for login shells
    - Sourced when you start a shell
- Quoting

- Commands
    - File management
        - `touch` - create a file, update access/modified times
        - `mv` - move a file
        - `mkdir` - make a directory
        - `mkdir -p` - make a directory, and intermediate directories
        - `rm` - delete a file
        - `rm -rf` - remove recursively, force (DANGER)
        - `rmdir` - delete an empty directory
        - `cp ` - copy a file
        - `rename` - rename files
        - `chmod` - change file permissions
        - `chown` - change file owner
    - Reading files
        - `cat`
        - `less`
        - `nano`
        - `vim`
        - `head`
        - `tail`
    - Find
        - `grep`
        - `find`
        - `which`
        - `whereis`
        - `whatis`
        - `man`
        - `locate`
    - Text processing
        - `sed`
        - `cut`
        - `sort`
        - `unique`
        - `diff`
        - `cmp`
    - Network
        - `ping`
        - `traceroute`/`tracepath`
        - `curl`
        - `wget`
        - `apt-get`
        - `tar`
        - `firefox`
    - Other`
        - `env`
        - `alias`
        - `cron`/`crontab`
        - `notify-send`
        - `echo`
        - `xargs`
        - `date`
        - `cal`
        - `source`
        - `tee`
        - `time`
        - `bc`
        - `yes`
        - `fortune`
        - `cowsay`
        - `clear`
        - `top`
        - `htop`
        - `write`/`wall`
- Globbing