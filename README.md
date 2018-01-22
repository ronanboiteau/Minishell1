# Minishell1

{EPITECH.} first year project.

C shell that can execute basic commands.

Take a look at [42sh](https://github.com/ronanboiteau/42sh) if you're looking for a shell capable of executing more complex commands (pipes, redirections...).

This shell is based on [tcsh](https://en.wikipedia.org/wiki/Tcsh).

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution) or [Apple's macOS](https://en.wikipedia.org/wiki/MacOS)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `mysh` executable file.

## Features
 - Execute basic commands
 - Execute multiple commands with separators
 - Can manage its own environment
 - Builtin commands:
   - `builtins`
   - `cd / chdir`
   - `echo`
   - `env [-0] [--null] [-u]`
   - `printenv`
   - `pwd`
   - `setenv`
   - `unsetenv`
 - Prompt based on last exit status
 - Support for non-interactive mode

## Author

* **Ronan Boiteau** ([GitHub](https://github.com/ronanboiteau) / [LinkedIn](https://www.linkedin.com/in/ronanboiteau/))
