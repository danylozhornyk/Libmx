#include "libmx.h"

char *mx_strtrim(const char *str)
{
    char* start = (char *)str;
    char* end = (char *)(str + mx_strlen(str) - 1);
    while (*start && mx_is_space(*start))
    {
        start++;
    }
    while (end > start && mx_is_space(*end))
    {
        end--;
    }
    *(end + 1) = '\0';
    return start;
}
