# Lesson 1: Life In The Shell 

```
               __
    .,-;-;-,. /'_\ I love my shell
  _/_/_/_|_\_\) /
'-<_><_><_><_>=/\
  `/_/====/_/-'\_\
   ""     ""    ""
```

The goals of this lesson are:
    - Understand what a shell is
    - Cover the basics of interacting with a shell 
    - Learn some tips and tricks to make the most of your shell 
    - Touch on some operating systems concepts
    - Whet your curiosity to learn more

## Table of Contents

- [What is a shell?](#what-is-a-shell-)
  * [Not a Terminal](#not-a-terminal)
  * [REPL (Read Evaluate Print Loop)](#repl--read-evaluate-print-loop-)
  * [What is a Program?](#what-is-a-program-)
- [Navigation](#navigation)
  * [Aliases](#aliases)
  * [History](#history)
  * [Keyboard Shortcuts](#keyboard-shortcuts)
- [Commands](#commands)
  * [Usage](#usage)
  * [Help](#help)
  * [Composition](#composition)
  * [File Globbing](#file-globbing)
  * [Environment Variables](#environment-variables)
- [Users/Groups](#users-groups)
  * [Permissions](#permissions)
- [Process Management](#process-management)
  * [Viewing processes](#viewing-processes)
  * [Running processes in the background](#running-processes-in-the-background)
  * [Signals/killing processes](#signals-killing-processes)
- [Scripting](#scripting)
  * [Shebang](#shebang)
  * [Sourcing](#sourcing)
- [Appendix: Useful Commands](#appendix--useful-commands)

## What is a shell?

"In computing, a shell is a user interface for access to an operating system's
services." - [Wikipedia](https://en.wikipedia.org/wiki/Shell_(computing))

"Shell" because it's the outermost layer around the operating system kernel.

Operating system services:

- Users And Groups (i.e. permissions)
- File Management and I/O
- Device Management
- Memory Management
- Process Management
- Scheduling
- Threading
- Time
- Network I/O (i.e. sockets)
- Interprocess Communication (e.g. signals, pipes)

See [The Linux Programming Interface](https://github.com/shihyu/Linux_Programming/blob/master/books/The%20Linux%20Programming%20Interface%20-%20A%20Linux%20and%20UNIX%20System%20Programming%20Handbook.pdf)

### Not a Terminal

A shell is **not** a terminal! These are different concepts (even if we often
use the words interchangeably in normal conversation).

A terminal emulator is a software program that emulates an old hardware
terminal, much like a gameboy emulator emulates a physical gameboy.

A shell is an interactive program whose input/output is typically
provided/displayed via a terminal.

Examples of terminals include:

- xterm
- gnome-terminal
- Terminal (macOS)
- ITerm2 (macOS)
- MinTTY (Windows)
- PuTTY (Windows)
- ConEmu (Windows)
- [Cool Retro Term](https://github.com/Swordfish90/cool-retro-term#screenshots)

`ps aux | grep "bash\|term"`

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

### What is a Program?

A shell is a REPL, which is a special kind of program. But what is a program?

The word "program" can be vague

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

## Navigation

In a shell, you are always located within a particular directory in the
filesystem (the "current working directory"). You start within your user's
`$HOME` directory (`~`).

- `pwd` - print working directory
- `ls` - list files in directory
    - `ls -a`
    - `ls -lh`
    - `ls -R`
- `tree` - display directory tree
- `cd` - change directory
    - `cd`
    - `cd /`
    - `cd ~`
    - `cd ..`
    - `cd -`
    - `cd ~user`
    - `$CDPATH` - like `$PATH`, but for `cd`
- `dirs` - alternative to `cd` that retains history of directories visited
    - `dirs` - list directory history
    - `pushd` - change directories and add it to the history
    - `popd` - go back in the directory history

### Aliases

Aliases are shortcuts for other commands. Some might already be present on your
system.
- `alias` - view all current aliases
- `alias we=whatever` - create a new alias
- Only for the current shell session (unless in .bashrc)
- Also, see `git config --global alias.we "whatever"`

Links are file-system aliases. In other words, they are files that link to
other files elsewhere on the system.
    - `ln` - hard link
    - `ln -s` - soft/symbolic link, or symlink

### History

The shell keeps a history of all commands entered. Learning to leverage this
effectively will give you a huge productivity/efficiency boost.

Basic history commands

- `history`
- `history 5`
- `!5` - execute command #5 from history
- `!-5` -execute command 5 lines back in history
- `!!` - last command
    - e.g. `sudo !!`
- `!whatever` - last command that starts with "whatever"
- `!*` - all args of last command
- `!$` - last arg of last command

Useful settings

- `shopt -s histappend` - Only append to history file
- `export HISTCONTROL=ignoreboth:erasedups`
- `export HISTSIZE=10000
- `export HISTFILESIZE=50000`
- `export HISTIGNORE='ls:bg:fg:history'`

Searching history

- `ALT-SHIFT-,` - Jump to beginning of history
- `ALT-SHIFT-.` - Jump to end of history
- `CTRL-r` - search backwards
- `CTRL-s` - search forwards
- `CTRL-g` - stop searching
- `CTRL-p` - Go back in history
- `CTRL-n` - Go forward in history
- `ALT-r` - Revert changes to line in history


### Keyboard Shortcuts

Bash has a bunch of built-in keyboard shortcuts that make it much easier to
create/edit/delete text at the command line. These may differ between
environments, and depending on which options have been set. Some programs may
also interfere with some of these shortcuts (e.g. `tmux`/`screen`/`byobu`).

Movement

- `CTRL-b` - Move cursor back one character 
- `CTRL-f` - Move cursor forward one character
- `ALT-b` - Move cursor backward one word
- `ALT-f` - Move cursor forward one word
- `CTRL-a` - Move to beginning of line
- `CTRL-e` - Move to end of line
- `CTRL-xx` - Move cursor between start of line and current position

Editing

- `CTRL-t` - Swap last two characters
- `ALT-t` Swap last two words
- `CTRL-y` - Use last text deleted/cut
- `ALT-.` - Use last word of the previous command
- `ALT-u` - Uppercase from cursor to end of word
- `ALT-l` - Lowercase from cursor to end of word
- `CTRL+\_` - Undo

Deleting

- `CTRL-h` - Delete character before cursor
- `CTRL-d` - Delete character under cursor
- `CTRL-w` - Delete word before cursor
- `ALT-d` - Delete word after cursor
- `CTRL-u` - Delete everything before cursor
- `CTRL-k` - Delete everything after cursor

Control

- `CTRL-j` - Enter/return
- `CTRL-o` - Enter/return
- `CTRL-l` - Clear screen
- `CTRL-s` - Stop output to screen
- `CTRL-q` - Resume output to screen
- `CTRL-c` - SIGINT
- `CTRL-z` - SIGSTOP
- `CTRL-d` - End of file

Note that all of the above shortcuts are "emacs" shortcuts. Alternatively,
you can use "vi" editing mode by setting the following option in your .bashrc:

`set -o vi`

Use `bind -P` to see a list of your current key bindings.

## Commands

A shell command can include the following

- Program name
    - Searches for it in the `$PATH`
    - Use `which` to see which program will be called
- Arguments - technically, everything that comes after the command name
    - Options - e.g. `docker-compose -f docker-compose.backend.yml`
    - Flags - e.g. `ls -R`
    - Other arguments (often just referred to as "arguments")
- Environment variables
    - `VAR=whatever bash -c 'echo $VAR'`
- stdin, stdout, stderr

### Usage

Almost all good commands have a [usage message](https://en.wikipedia.org/wiki/Usage_message)
that explains the available arguments/options/flags. Usage messages have a
standard syntax:

- Square brackets indicate optional arguments `[-b]`
- Angled brackets indicate required arguments `<pid>`
- Exclusive parameters are separated by vertical bars/pipes `[-f | -g]`

For example: 

```
Usage: program [-aDde] [-f | -g] [-n number] [-b b_arg | -c c_arg] req1 req2 [opt1 [opt2]]
```

### Help

You can get help for most commands right in your terminal

- `help` - Bash help
- `--help` - Command-specific help
    - `man --help`
    - `cd --help`
- `man` - manual pages
    - `man which`
    - `man man` :mindblown:
        - sections - e.g. `man 7`
    - `man cd` :thinking:
- `type` - type of command (builtin, alias, program, etc.)
    - `type type`
    - `type cd`
    - `type which`
- `which` - location of command binary
    - `which man`
    - `which which`
    - `which cd`
    - `which type`
- `whereis` - location of binary, source code, and documentation
- `whatis` - brief description of command
- `firefox www.google.com`

### Composition

"Make each program do one thing well."
"Expect the output of every program to become the input to another, as yet unknown, program."
- [The Unix Philosophy](https://en.wikipedia.org/wiki/Unix_philosophy)

Subshells

- `()` - Runs the commands inside the parentheses in a separate subshell
    - `( ps aux | grep bash )`

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
- `<()` - Treat output of command as a file
    - `grep "bash" <(cat README.md)`
- /dev/null - a useful black hole
    - `yes > /dev/null`

Pipes and pipelines

- `|` - use one process's stdout as the next process's stdin
- `cat README.md | grep "bash"`

Exec and eval

- `exec` - peplace the current shell with the given command
    - `exec bash`
    - `exec bc`
- `eval` - run the arguments as a command in the current shell
    - `cmd="bar=foo" eval $cmd; echo $bar`

### File Globbing

File "globbing" is a built-in mechanism for expanding file path wildcard
patterns. It is often confused with regular expressions, but it is technically
a different thing.

The rules are

- `?` - matches any single character
- `*` - matches any string, including the empty string
- `[abc]` - matches any of the characters contained within the brackets
- `[!abc]` - matches any character not contained within the brackets
- `[a-c]` - matches any character in the range from a to c

For more information, see `man 7 glob`

### Environment Variables

Environment variables are parameters that can affect the behavoir of programs,
and can be used in string interpolation. Use the `env`/`printenv` commands to
view a list of all currently set environment variables.

Built-in Variables

- `$HOME`
- `$PWD`
- `$OLDPWD`
- `$USER`
- `$PATH`
- `$CDPATH`
- `$TERM`
- `$SHELL`
- `$DISPLAY`
- `$LANG`
- `$LANGUAGE`
- `$RANDOM`
- `$SECONDS`
- `$LINENO`

Setting Variables

- Inline
    - Only available for the current command
    - `VAR=whatever bash -c 'echo "$VAR"'`
- Exported
    - Available for all subsequent commands/subshells
    - Often in .bashrc or other sourced file
    - `export VAR=whatever`

Referencing Variables

- `$VAR`
- `${VAR}`
- Single vs double quotes
    - `VAR=yo; echo "$VAR"`
    - `VAR=yo; echo '$VAR'`
- `${VAR:-default}` - Use "default" as the default value, if the variable
  is not set
- `${VAR:=default}` - If variable is not set, set it to "default"
- `${VAR:+alt}` - If variable is set, use "alt" instead
- `${VAR:?err}` - If parameter is set, use it. Otherwise print "err" and
  abort with exit code 1.
- `${#VAR}` - Length of the string contained in the variable
- `${VAR#pattern}` - Remove shortest instance of "pattern" from beginning
  of variable
- `${VAR##pattern}` - Remove longest instance of "pattern" from beginning
  of variable
- `${VAR%pattern}` - Remove shortest instance of "pattern" from end of
  variable
- `${VAR%%pattern}` - Remove longest instance of "pattern" from end of
  variable
- `${VAR:pos}` - Variable starting from offset pos
- `${VAR:pos:len}` - Variable starting from offset pos with length len
- `${VAR/find/replace}` - Replace the first instance of "find" with
  "replace"
- `${VAR//find/replace}` - Replace all instances of "find" with "replace"
- `${!VAR}` - Indirect reference to 

## Users/Groups

In a shell, you are always logged in as a particular user.

- `$USER`
- `whoami`

The `/etc/passwd` file contains a list of all of the users on the system,
along with their home directories and startup commands. Actual passwords are
stored encrypted in the `/etc/shadow` file.

The `/etc/group` file contains a list of all of the groups on the system, and
who belongs to each.

### Permissions

Users/groups are the fundamental units of the operating system's permission
system. All files have a user/group, as well as a set of permissions that
explain which users/groups can access the file in which ways. All processes
also have a set of user/group ids, which represent the permissions of the
process.

File permissions can be viewed with `stat` or `ls -l`.

Process user/groups can be viewed with `ps`.

File ownership can be changed with `chown`

- `chown postgres`

File permissions can be changed with `chmod`

- `chmod 644`
- `chmod u+rw`
- `chmod go-wx`
- `chmod u+rw-x`

Your current active user can be changed with `sudo`

- `sudo -s`.
- `sudo -su postgres`.

## Process Management

A process is an instance of an executing program.

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
    - `echo "yo" > /proc/PID/fd/1` :mindblown:

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

## Scripting

Any commands entered at the terminal can also be written into a bash script,
which is basically a reusable series of commands. To run a script, pass the
filename to the `bash` command, like so:

`bash ./example.sh`

This runs the code in `example.sh` in a subshell, rather than in the current
shell. In other words, it runs it in a separate instance of bash (this should
be evident from the fact that the command begins with `bash`).

If you make the file executable (e.g. `chmod u+x`), you can run
it directly on the command line, as if it were any other program:

`./example.sh`

Note that it will still be run in a separate subshell, despite the fact that
we've omitted the explicit `bash` part of the command (this is assumed).

### Shebang

Often, people include a "shebang" at the top of the file, which tells bash
what program to use to interpret/execute the commands in the file. A shebang
begins with `#!` followed by the absolute path to the executable that should be
used to interpret the program. For example: `#!/bin/bash`.

This can also be used to specify other programs, besides a shell, which should
be used to interpret the instructions contained in the file. For example,
`#!/usr/bin/python`.

Often, it is useful to put shells scripts in your `$PATH` so that they can be
accessed from anywhere. One common location for such scripts is `$HOME/bin`.
You might also want to remove the `.sh` suffix from the names of scripts in
this folder so that they can be run from anywhere like a first-class, bona-fide
program on your computer:

`example`

### Sourcing

Normally, when you run a bash script, it is executed in a separate subshell.
However, "sourcing" a file refers to the process of running the commands in a
file within the current shell. This is how files like `.bashrc` and
`.bash_profile` are run at the start of a session. Files can be sourced with
either the `source` command or the `.` directive.

- `source ~/.bashrc`
- `. ~/.bashrc` 

Sourcing a file makes it possible for shell-specific configuration to take
effect - for example, `export` and `alias` commands.

Some files are sourced automatically at the start of a shell session:

- `.bashrc` - sourced at start of interactive non-login shells
- `.profile`/`.bash_profile` - sourced at start of login shells

## Appendix: Useful Commands

Help

- `help`
- `type`
- `man`
- `which`
- `whereis`
- `whatis`

File management

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

Viewing/editing files

- `cat`
- `less`
- `nano`
- `vim`
- `head`
- `tail`

Searching

- `grep`
- `find`
- `locate`

Text Processing

- `basename`
- `cut`
- `sed`
- `awk`
- `sort`
- `unique`
- `diff`
- `cmp`
- `wc`

Process Management

- `su`
- `sudo`
- `ps`
- `top`
- `htop`

Networking

- `ping`
- `traceroute`/`tracepath`
- `ifconfig`
- `curl`
- `wget`
- `firefox`
- `google-chrome`
- `apt-get`

Compression

- `ar`
- `tar`
- `zip`

Miscellaneous

- `source`
- `env`
- `echo`
- `tee`
- `xargs`
- `clear`
- `write`/`wall`
- `alias`
- `cron`/`crontab`
- `notify-send`
- `date`
- `cal`
- `time`
- `bc`
- `yes`
- `fortune`
- `cowsay`
