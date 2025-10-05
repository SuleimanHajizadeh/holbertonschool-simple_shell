#include "main.h"

/**
 * shell_error - Prints default error message and returns EXIT_FAILURE
 */
int shell_error(void)
{
    perror("./hsh - not found");
    return (EXIT_FAILURE);
}
