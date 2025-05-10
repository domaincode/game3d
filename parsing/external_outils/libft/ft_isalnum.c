
#include "libft.h"

int	ft_isalnum(int p)
{
	if ((p >= 48 && p <= 57) || (p >= 65 && p <= 90) || (p >= 97 && p <= 122))
		return (1);
	return (0);
}
