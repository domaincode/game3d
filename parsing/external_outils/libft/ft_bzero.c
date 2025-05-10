#include "libft.h"

void	ft_bzero(void *str, size_t n )
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
