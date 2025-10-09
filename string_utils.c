#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(const char *s)
{
    int i = 0;

    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, <0 if s1<s2, >0 if s1>s2
 */
int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

/**
 * _strcpy - copies string src into dest
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: string
 * Return: pointer to new string
 */
char *_strdup(const char *s)
{
    char *dup;
    int len, i;

    if (!s)
        return (NULL);
    len = _strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    for (i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return (dup);
}

/**
 * _memcpy - copies memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (i = 0; i < n; i++)
        d[i] = s[i];
    return (dest);
}
