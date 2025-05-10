
#include "parsing.h"

long long	ft_condition(char *str, int i)
{
	if (i == 0)
		return (ft_atoi(str) << 16);
	if (i == 1)
		return (ft_atoi(str) << 8);
	if (i == 2)
		return (ft_atoi(str));
	return (0);
}
