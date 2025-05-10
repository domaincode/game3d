
#include "libft.h"

void	*ft_memset(void *str, int c, size_t b)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)str;
	i = 0;
	while (i < b)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
