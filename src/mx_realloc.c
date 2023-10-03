#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    size_t length = *((size_t *)((char *) ptr - sizeof(size_t)));
    if (size == 0) 
    {
        free(ptr);  
        return NULL;
    }
    if (ptr == NULL) 
    {
        return malloc(size);
    }
    size_t copy_size = (length < size) ? size : length ;
    void *tmp = (void *)malloc(copy_size);
    if (!tmp)
    {
        return NULL;
    }
    tmp = mx_memmove(tmp, ptr, size);
    free(ptr);
    return tmp;
}
