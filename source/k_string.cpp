#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "k_string.h"

size_t min (size_t a, size_t b);

/**
 * @brief Works for O(n)
 * @param [in] s string to find it's end
 * @returns Pointer to '\0' of the string
 */
char *k_strEnd(char * s);

size_t min (size_t a, size_t b)
{
    if (a < b)
        return a;
    else
        return b;
}

char * k_strEnd( char * s) {
    return s + strlen(s);
}

// ssize_t k_putc(const char c, int fd) 
// {
//     char s[2];
//     s[0] = c;
//     s[1] = '\0';
//     return write (fd, s, 1);
// }

int k_puts (const char *s)
{
    size_t idx = 0;
    
    while (s[idx] != '\0')
    {
        if (putc (s[idx], stdout) == EOF)
        {
            return EOF;
        }

        idx++;
    }

    return putc ('\n', stdout);
}

const char *k_strchr (const char *s, int c) 
{
    if (c == '\0') 
    {
        return s + k_strlen (s);
    }

    size_t idx = 0;

    while (s[idx] != '\0')
    {
        if (s[idx] == c)
        {
            return (&s[idx]);
        }
        idx++;
    }
    
    return NULL;
}

size_t k_strlen (const char *string) 
{
    size_t count = 0;

    while (string[count] != '\0')  
    {
        count++;
    }

    return count;
}

char *k_strcpy (char *dst, const char *src)
{
    char  *p;

    p = (char *)mempcpy (dst, src, k_strlen(src));
    *p = '\0';
    
    return dst;
}

char *k_strncpy (char *dst, const char *src, size_t srcSize)
{
    size_t dstLen = min(k_strlen(src), srcSize);
    
    void *distEnd = mempcpy(dst, src, dstLen);

    memset(distEnd, 0, srcSize - dstLen);
    
    return dst;
}

char *k_strcat (char *dst, const char *src)
{
    k_strcpy(dst + strlen(dst), src);

    return dst;
}

char *k_strncat(char *dst, const char *src, size_t srcSize)
{
    size_t dstLen = min(k_strlen(src), srcSize);

    void *resEnd = mempcpy ((void*)k_strEnd (dst), src, dstLen);

    memset(resEnd, '\0', srcSize - dstLen);
    
    return dst;
}