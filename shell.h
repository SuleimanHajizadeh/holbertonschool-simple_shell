#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv, char **env);
void initialize_shell(char **env);
char *read_line(void);
void execute_line(char *line, char **env);
int _printf(const char *format, ...);

#endif /* SHELL_H */
