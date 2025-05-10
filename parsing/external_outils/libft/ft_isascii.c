
#include "libft.h"

int	ft_isascii(int m)
{
	if (m >= 0 && m <= 127)
		return (1);
	return (0);
}
