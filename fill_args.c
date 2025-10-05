#include "main.h"

/**
 * fill_args - tokenizes input_buffer into argv array
 */
char **fill_args(char *input_buffer)
{
    char *token;
    char *buffer_copy;
    int count = 0, i = 0;
    char **argv;

    /* Count tokens */
    buffer_copy = input_buffer;
    token = strtok(buffer_copy, " \t");
    while (token)
    {
        count++;
        token = strtok(NULL, " \t");
    }

    /* Allocate array */
    argv = malloc((count + 1) * sizeof(char *));
    if (!argv)
        return (NULL);

    /* Fill argv */
    token = strtok(input_buffer, " \t");
    while (token)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t");
    }
    argv[i] = NULL;

    return (argv);
}
