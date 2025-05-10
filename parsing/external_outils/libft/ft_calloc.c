
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	res = malloc(sizeof(char) * (count * size));
	if (!res)
		return (NULL);
	ft_memset(res, 0, size * count);
	return (res);
}
