#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
unsigned char * d;
const unsigned char *s;
size_t i;

d = (unsigned char*)dest;
s = (const unsigned char*)src;

i = 0;

if (!dest && !src)
return (NULL);

while (i < n)
{
    d[i] = s[i];
    i++;
}

return (dest);

}
