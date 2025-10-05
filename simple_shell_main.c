#include "main.h"

/**
 * main - Entry point of shell
 */
int main(void)
{
    char buffer[1024];
    char *argv[64];
    int ret = 0;
    ssize_t nread;
    int interactive;

    signal(SIGINT, SIG_IGN);

    interactive = isatty(STDIN_FILENO);

    while (1)
    {
        if (interactive)
            write(1, "#simple_shell$ ", 14);

        nread = read(STDIN_FILENO, buffer, 1023);
        if (nread <= 0)
        {
            if (interactive)
                write(1, "\n", 1);
            break;
        }

        buffer[nread] = '\0';
        /* remove trailing newline */
        if (buffer[nread - 1] == '\n')
            buffer[nread - 1] = '\0';

        if (buffer[0] == '\0')
            continue;

        if (buffer[0] == 'e' && buffer[1] == 'n' && buffer[2] == 'v' && buffer[3] == '\0')
        {
            print_env();
            continue;
        }

        if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' &&
            buffer[3] == 't' && buffer[4] == '\0')
            break;

        /* tokenize input manually (or using fill_args) */
        char *tmp = buffer;
        int argc = 0;
        tokenize:
        char *tok = strtok(tmp, " \t");
        tmp = NULL;
        while (tok && argc < 63)
        {
            argv[argc++] = tok;
            tok = strtok(NULL, " \t");
        }
        argv[argc] = NULL;

        if (argv[0])
            ret = execute_command(argv);
    }

    return (ret);
}
