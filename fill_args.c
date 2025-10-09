#include "main.h"

/**
 * fill_args - split a line into arguments (no strtok)
 * @line: input line
 * Return: NULL-terminated array of arguments
 */
char **fill_args(char *line)
{
    char **argv = NULL;
    int argc = 0, i = 0, start = 0, len = 0;

    if (!line)
        return (NULL);

    /* get length of input */
    while (line[len])
        len++;

    while (i <= len)
    {
        /* skip spaces */
        while (i < len && (line[i] == ' ' || line[i] == '\t'))
            i++;

        start = i;

        /* find end of word */
        while (i < len && line[i] != ' ' && line[i] != '\t')
            i++;

        if (i > start) /* found a word */
        {
            char *arg;
            int j, word_len = i - start;

            argv = realloc(argv, sizeof(char *) * (argc + 2));
            if (!argv)
                return (NULL);

            arg = malloc(word_len + 1);
            if (!arg)
                return (NULL);

            for (j = 0; j < word_len; j++)
                arg[j] = line[start + j];
            arg[word_len] = '\0';

            argv[argc] = arg;
            argc++;
        }
        i++;
    }
    if (argv)
        argv[argc] = NULL;

    return (argv);
}
