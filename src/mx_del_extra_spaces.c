#include "libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    char *strTrimed = mx_strtrim(str);
    int len = mx_strlen(strTrimed);
    char *result = (char *)malloc(len);
    for (int i = 0, j = 0; j < len; i++, j++)
    {
        if (!mx_is_space(strTrimed[j]))
        {
            result[i] = strTrimed[j];
        }else
        {
            result[i] = strTrimed[j];
            while (mx_is_space(strTrimed[j+1]))
            {
                j++;
            }
        }
        
    }
    return result;
}
