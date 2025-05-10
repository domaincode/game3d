
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	char			*p;
	char			f;

	i = 0;
	f = (char)c;
	p = (char *)str;
	while (p[i] != f)
	{
		if (p[i] == '\0')
			return (NULL);
		i++;
	}
	return (p + i);
}
