#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * @env: Environment variables
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **env)
{
    char *line;

    (void)argc;
    initialize_shell(env);
    while (1)
    {
        if (isatty(STDIN_FILENO))
            _printf("$ ");
        line = read_line();
        if (!line)
            break;
        if (*line)
            execute_line(line, env);
        free(line);
    }
    return (0);
}
