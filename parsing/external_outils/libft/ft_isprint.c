
#include "libft.h"

int	ft_isprint(int v)
{
	if (v >= 32 && v <= 126)
		return (1);
	return (0);
}
