#include "main.h"

/**
 * _getenv - Returns value of environment variable
 * @name: Variable name
 * Return: Pointer to value or NULL
 */
char *_getenv(const char *name)
{
    int i;
    size_t len;

    if (!name || !environ)
        return (NULL);

    len = strlen(name);
    for (i = 0; environ[i]; i++)
    {
        size_t j = 0;
        while (j < len && environ[i][j] == name[j])
            j++;
        if (j == len && environ[i][j] == '=')
            return (&environ[i][len + 1]);
    }
    return (NULL);
}
