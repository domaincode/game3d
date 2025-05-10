
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while (str[i] != '\0' || str1[i] != '\0')
	{
		if (str[i] > str1[i])
			return (1);
		else if (str[i] < str1[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while ((i < n) && (str[i] != '\0' || str1[i] != '\0'))
	{
		if (str[i] > str1[i])
			return (1);
		else if (str[i] < str1[i])
			return (-1);
		i++;
	}
	return (0);
}
