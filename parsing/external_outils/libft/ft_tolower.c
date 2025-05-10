
#include "libft.h"

int	ft_tolower(int w)
{
	if (w >= 65 && w <= 90)
		return (w + 32);
	return (w);
}
