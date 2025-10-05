#include "main.h"

/**
 * print_env - Prints all environment variables.
 */
void print_env(void)
{
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
