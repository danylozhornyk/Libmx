#include "libmx.h"

char *mx_strdup(const char *s1)
{
    char *newstr = (char*)malloc(mx_strlen(s1));
    mx_strcpy(newstr, s1);
    return newstr;
}
