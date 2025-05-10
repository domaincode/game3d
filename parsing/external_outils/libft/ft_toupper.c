
#include "libft.h"

int	ft_toupper(int s)
{
	if ((s >= 'a' && s <= 'z'))
		return (s - 32);
	return (s);
}
