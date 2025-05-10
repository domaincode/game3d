
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	f;

	i = 0;
	f = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == f)
			return (str + i);
		i++;
	}
	return (NULL);
}
