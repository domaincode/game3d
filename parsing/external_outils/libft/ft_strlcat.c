
#include "libft.h"

size_t	ft_strlcat(char *d, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	j = 0;
	if (d == NULL && size == 0)
		return (ft_strlen((char *)src));
	i = ft_strlen(d);
	k = ft_strlen((char *)src);
	l = i + k;
	if (size == 0 || i > size)
		return (k + size);
	while (src[j] && i + 1 < size)
	{
		d[i] = src[j];
		j++;
		i++;
	}
	d[i] = '\0';
	return (l);
}
