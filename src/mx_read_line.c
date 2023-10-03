#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    char *buf = mx_strnew(buf_size);
    char *str = mx_strnew(buf_size);
    if (buf_size == 0 || buf_size > 2147483648 
        || buf == NULL || str == NULL || fd <= 0)
    {
        return -2;
    }
    size_t type;
    while ((type = read(fd, buf, buf_size)) > 0)
    {
        mx_strcat(str, buf);
    }
    if (type < 0)
    {
        return -1;
    }
    int index = mx_get_char_index(str, delim);
    if (index == -1)
    {
        *lineptr = str;
        return -1;
    }
    else
    {
        mx_strncpy(*lineptr, str, index);
    }
    close(fd);
    free(buf);
    free(str);
    return index;
}
