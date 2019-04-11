# Lesson 1: Life In The Shell 

```
               __
    .,-;-;-,. /'_\ I love my shell
  _/_/_/_|_\_\) /
'-<_><_><_><_>=/\
  `/_/====/_/-'\_\
   ""     ""    ""
```

## What is a shell?

"In computing, a shell is a user interface for access to an operating system's
services." - [Wikipedia](https://en.wikipedia.org/wiki/Shell_(computing))

Operating system services include:
    - Users And Groups (i.e. permissions)
    - File Management and I/O
    - Memory Management
    - Process Management
    - Scheduling
    - Threading
    - Time
    - Network I/O (i.e. sockets)
    - Interprocess Communication (e.g. signals, pipes)

See [The Linux Programming Interface](https://github.com/shihyu/Linux_Programming/blob/master/books/The%20Linux%20Programming%20Interface%20-%20A%20Linux%20and%20UNIX%20System%20Programming%20Handbook.pdf)

### REPL (Read Evaluate Print Loop)

A shell is a special kind of program called a "Read Evaluate Print Loop".

Examples of REPLs include:
    - `python`
    - `node`
    - `psql`
    - `bc`

Examples of shells:
    - sh (Bourne shell)
    - csh (C shell)
    - ksh (Korn shell)
    - **bash** (Bourne Again Shell)
    - zsh (Z shell)
    - fish (Friendly Interactive Shell)
    - ash (Almquist Shell)
    - dash (Debian Almquist Shell)

## Navigation

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

## What is a program?

A shell is special kind of program. But what is a program?

The word "program" is vague
    - Source vs compiled 
    - Compiled vs interpreted

Fundamentally, a program is set of instructions
    - Compiled
        - Human readable source code
        - Compiled to binary
        - Run directly as machine code
            - `fact`
    - Interpreted
        - Human readable scripts
        - Input to other programs
            - `bash -c "echo yo"`
            - `python my_script.py`
            - `node index.js`
        - Shebang (`#!/bin/bash`)

In any case, a program is **data**
    - Von Neumann architecture
        - Code/instructions are data
        - "Von Neumann architecture is based on the stored-program computer
          concept, where instruction data and program data are stored in the
          same memory.  This design is still used in most computers produced
          today."
        - Revolutionary, at the time (1945)
    - `which` - searches `$PATH` for the program with that name
        - `which fact`
        - `which bash`
        - `which which` :mindblown:
        - `which cd` :thinking:

## What is a process?

An instance of an executing program.

Processes have:
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
    - An exit code
        - 0 means success
        - greater than 0 means error
        
All processes start from the [init](https://en.wikipedia.org/wiki/Init)
process, which has PID 1, and is the first process started. Modern linux
distros often use [systemd](https://en.wikipedia.org/wiki/Systemd).

### Viewing processes

There are many ways to view information about running processes on your system

- `ps` - processes with same user, associated with same terminal
- `ps aux` - all running processes
- `top`/`htop` - all processes, real-time, interactive
- /proc - [Everything is a File](https://en.wikipedia.org/wiki/Everything_is_a_file)
    - `sleep 1000 &`
    - `stat /prod/PID`
    - `cat /proc/PID/cmdline`
    - `ll /proc/PID/cwd`
    - `echo "yo" > /proc/PID/fd/1`
    - :mindblown:

### Running processes in the background

When starting a process
    - `&` at end of command
    - e.g. `sleep 10 && echo "yo" &`

If already in foreground
    - `ctrl-z` to pause it (sends `SIGSTP` signal)
    - `bg` to run in background
    - `fg` to bring back into foreground

`jobs` - list background processes started in the current shell
    - Note that if you close the terminal, the background jobs will persist,
      but won't show up in `jobs` anymore

### Signals/killing processes

To kill a process, send a signal or close the input stream.

Keyboard shortcuts for foreground processes
    - `ctrl-c` - SIGINT, requests that a process shutdown
    - `ctrl-d` - End of file (EOF), often stops processes that read from stdin

Commands for background processes
    - `kill` - Sends a signal to a process (by PID)
        - `kill %1` - Send SIGINT to job [1]
        - `kill -s SIGINT`/`kill -2`
        - `kill -s SIGKILL`/`kill -9`
            - https://www.youtube.com/watch?v=Fow7iUaKrq4
        - `kill -s SIGKILL $$`
        - `kill $(jobs -p)`
    - `pkill`/`killall` - Sends a signal to a process (by name/pattern)
        - `pkill sleep`
        - `killall sleep`

Signals
    - `kill -l` - list all signals
    - `man 7 signal` - manual page for signals

## Anatomy of a shell command

A shell command to start a process includes
    - Program name
        - Searches for it in the `$PATH`
        - Use `which` to see which program will be called
    - Arguments - everything that comes after the command name
        - Options - e.g. `docker-compose -f docker-compose.backend.yml`
        - Flags - e.g. `ls -R`
    - Environment variables
        - `VAR=whatever bash -c 'echo $VAR'`
    - Stdin, Stdout, Stderr

### Usage

Almost all good commands have a [usage message](https://en.wikipedia.org/wiki/Usage_message)
that explains the available arguments/options/flags. These messages follow a
conventional syntax:

    - Square brackets indicate optional arguments `[-b]`
    - Angled brackets indicate required arguments `<pid>`
    - Exclusive parameters are separated by vertical bars/pipes `[-f | -g]`

```
Usage: program [-aDde] [-f | -g] [-n number] [-b b_arg | -c c_arg] req1 req2 [opt1 [opt2]]
```

### Help

You can get help for almost any command right in your terminal

    - `--help`
        - `man --help`
        - `cd --help`
    - `man` (i.e. "manual")
        - `man which`
        - `man man` :mindblown:
        - `man cd` :thinking:
    - https://www.google.com

### Composing commands

"Make each program do one thing well."
"Expect the output of every program to become the input to another, as yet unknown, program."
- [The Unix Philosophy](https://en.wikipedia.org/wiki/Unix_philosophy)

Combining commands
    - `;` - run multiple commands, one after the other
        - `sleep 10; echo "yo"`
    - `&&` - only run a command if the first command succeeds
        - `bash -c 'exit 0' && echo "yo"`
        - `bash -c 'exit 1' && echo "yo"`
    - `||` - only run a command if the first command fails
        - `bash -c 'exit 0' || echo "yo"`
        - `bash -c 'exit 1' || echo "yo"`
    - `$()` (or backticks) - "command substitution"
        - `echo "Today's date is: $(date)"`
        - ``echo "Today's date is: `date```

Redirection
    - `<` - redirect file to stdin
        - `grep "bash" < README.md` vs `grep "bash" README.md`
    - `>` - redirect stdout to file (truncate it first)
        - `echo "yo" > out.txt`
    - `>>` - redirect stdout to file (append to it)
        - `echo "yo" > out.txt && echo "dude" >> out.txt`
    - `2>&1` - redirect stderr to stdin
    - `&>` - redirect both stdout and stderr to a file
    - `<<< ''` - "Herestring" - redirect string literal to stdin
        - `cat <<< "yo"`
    - `<< END ...\n END` - "Heredoc" - redirect input stream literal to stdin
    - `<$()` - Treat output of command as a file
        - `grep "bash" <$(cat README.md)`
    - /dev/null - a useful black hole
        `yes > /dev/null`

Pipes and pipelines
    - `|` - use one process's stdout as the next process's stdin
    - `cat README.md | grep "bash"`

## History

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
    - `ctrl-r` - search backwards
    - `ctrl-s` - search forwards
    - `ctrl-g` - stop searching

## Environment variables

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

### Quoting and string interpolation

### File Globbing

## Making your shell your own

`.bashrc`
    - Sourced at start of interactive non-login shells
        - `source ~/.bashrc`
        - `. ~/.bashrc` 
    - `.profile` and `.bash_profile` are for login shells

`alias`
    - Define your own aliases for commands
    - `alias dc=docker-compose`
    - Only for the remainder of the shell session, unless in .bashrc


## Useful command appendix

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
