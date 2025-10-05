#include "main.h"

/**
 * file_exist - Checks if a file exists
 */
int file_exist(char *file)
{
    struct stat st;

    if (stat(file, &st) == 0)
        return (0);
    return (1);
}

/**
 * find_cmd_path - Finds full path of command using PATH
 */
int find_cmd_path(char *cmd, char *work_buffer)
{
    char *path_var = _getenv("PATH");
    char *token;
    int i, j;

    if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
    {
        if (file_exist(cmd) == 0)
        {
            for (i = 0; cmd[i]; i++)
                work_buffer[i] = cmd[i];
            work_buffer[i] = '\0';
            return (0);
        }
        return (1);
    }

    if (!path_var || !*path_var)
        return (1);

    /* iterate PATH directories */
    i = 0;
    while (path_var[i])
    {
        int k = 0;
        char dir[1024];

        /* copy until ':' or end */
        j = 0;
        while (path_var[i] && path_var[i] != ':' && j < 1023)
            dir[j++] = path_var[i++];
        dir[j] = '\0';
        if (path_var[i] == ':')
            i++;

        /* build full path */
        j = 0;
        while (dir[j])
        {
            work_buffer[j] = dir[j];
            j++;
        }
        work_buffer[j++] = '/';

        int m = 0;
        while (cmd[m])
            work_buffer[j++] = cmd[m++];
        work_buffer[j] = '\0';

        if (file_exist(work_buffer) == 0)
            return (0);
    }
    return (1);
}

/**
 * execute_command - fork and exec command
 */
int execute_command(char *argv[])
{
    pid_t pid;
    int status;
    char work_buffer[1024];

    if (find_cmd_path(argv[0], work_buffer))
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        return (127);
    }

    pid = fork();
    if (pid < 0)
        return (shell_error());
    if (pid == 0)
    {
        execve(work_buffer, argv, environ);
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        _exit(127);
    }
    wait(&status);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (status);
}
