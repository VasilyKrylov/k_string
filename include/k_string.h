#ifndef KVAS_STRINGS
#define KVAS_STRINGS

#include <stdio.h>

size_t k_strlen(const char *string);
// ssize_t k_putc(char c, int fd);
int k_puts(const char *s);
const char *k_strchr(const char *s, int c);
char *k_strncpy(char *dst, const char *src, size_t dsize);
char *k_strcpy(char *dst, const char *src);
char *k_strcat(char *dst, const char *src);
char *k_strncat(char *dst, const char *src, size_t srcSize);


#endif // KVAS_STRINGS