#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * fill_args - Tokenizes a string into an array of arguments
 *              without using strtok (C89 compatible)
 * @line: The input command line
 * Return: Null-terminated array of strings (arguments)
 */
char **fill_args(char *line)
{
    char **argv = NULL;
    int argc = 0;
    int i, start, len;
    char *arg;

    if (line == NULL)
        return (NULL);

    len = 0;
    while (line[len] != '\0')
        len++;

    i = 0;
    while (i < len)
    {
        /* Skip leading spaces and tabs */
        while ((line[i] == ' ' || line[i] == '\t') && i < len)
            i++;

        if (i >= len)
            break;

        start = i;

        /* Find the end of the word */
        while (line[i] != ' ' && line[i] != '\t' && i < len)
            i++;

        /* Allocate memory for the argument (+1 for '\0') */
        arg = malloc((i - start + 1) * sizeof(char));
        if (arg == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        /* Copy characters to arg */
        {
            int j;
            for (j = 0; j < i - start; j++)
                arg[j] = line[start + j];
        }
        arg[i - start] = '\0';

        /* Reallocate argv array */
        argv = (char **)realloc(argv, (argc + 2) * sizeof(char *));
        if (argv == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        argv[argc] = arg;
        argc++;
    }

    if (argv != NULL)
        argv[argc] = NULL; /* NULL-terminate argv */

    return (argv);
}
