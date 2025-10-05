# simple_shell

## Description
`simple_shell` is a basic Unix command line interpreter written in C. It reads and executes commands from standard input or from a file. This shell supports:
- Execution of simple commands (`ls`, `pwd`, `echo`, etc.)
- Built-in commands: `cd`, `exit`, `env`
- PATH lookup for external programs
- Error handling matching `/bin/sh`

## Compilation
To compile `simple_shell`:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

