#include "libmx.h"

void mx_del_strarr(char ***arr)
{
    int count = 0;
    while (*arr[count])
    {
        mx_strdel(&(*arr[count++]));
    }
    free(*arr);
    *arr = NULL;
}
