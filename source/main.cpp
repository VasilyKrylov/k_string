#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "k_string.h"

int main()
{
    // char tmpName[L_tmpnam];

    // tmpnam (tmpName);
    // printf ("tmpname: %s\n len: %lu\n", tmpName, strlen(tmpName));

    char s[11] = "01234";

    printf ("\'3\' on position: \t%ld\n", k_strchr(s, '3') - s);
    printf ("\'\\0\' on position: \t%ld\n", k_strchr(s, '\0') - s);

    char s2[] = "56789";
    
    k_strncat (s, s2, 5);
    
    k_puts("");

    printf ("s:\t%s\n"
            "s2:\t%s\n", 
            s, s2);

    k_puts("");

    printf ("\'4\' on position: \t%ld\n", k_strchr(s, '4') - s);
    printf ("\'7\' on position: \t%ld\n", k_strchr(s, '7') - s);
    printf ("\'\\0\' on position: \t%ld\n", k_strchr(s, '\0') - s);

    return 0;
}