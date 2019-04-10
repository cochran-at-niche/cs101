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
    - "In computing, a shell is a user interface for access to an operating
      system's services." - [Wikipedia](https://en.wikipedia.org/wiki/Shell_(computing))
        - Operating system services include:
            - Users And Groups (i.e. permissions)
            - File Management and I/O
            - Process Management
            - Memory Management
            - Threading
            - Time
            - Network Calls
            - Interprocess Communication (e.g. signals, pipes)
        - [The Linux Programming Interface](https://github.com/shihyu/Linux_Programming/blob/master/books/The%20Linux%20Programming%20Interface%20-%20A%20Linux%20and%20UNIX%20System%20Programming%20Handbook.pdf)
    - A program
    - REPL (Read Evaluate Print Loop)
        - Other examples:
            - python
            - node
            - psql
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
    - The word "program" can be vague
        - Source vs compiled 
        - Compiled vs interpreted
    - Fundamentally, a set of instructions
        - Compiled
            - Binary
            - Machine code
        - Interpreted
            - Scripts
            - Input to other programs
    - Data
        - Von Neumann architecture
            - Code/instructions _are_ data
        - `which`
            - `which bash`
            - `which which` :mindblown:
            - `cd` :thinking:
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
            - stdin (0)
            - stdout (1)
            - stderr (2)
            - files
            - sockets
            - pipes
            - etc (everything is a file)
    - `ps aux`
    - /proc
- Anatomy of a shell command
    - Arguments
    - Options
    - Flags
    - Help
        - `--help`
        - `man` (i.e. "manual")
            - `man which`
            - `man man` :mindblown:
            - `man cd` :thinking:
- Composing commands
    - Redirection
    - Pipes and pipelines
