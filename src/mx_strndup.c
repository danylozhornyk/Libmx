#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    int len = (int)n;
    char *newstr = (char*)malloc(len);
    mx_strncpy(newstr,s1,len);
    return newstr;
}
