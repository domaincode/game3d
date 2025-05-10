#include "parsing.h"

void    rgb_parse(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
	    if (str[i] == ',')
	    {
			if (i == 0 || i == (int)ft_strlen(str) - 1 || c >= 2)
				put_error("INVALID RGB");
			c++;
		}
		else if (str[i] != ' ' && str[i] != '\t' && !ft_isdigit(str[i]))
			put_error("INVALID RGB");
		i++;
	}
}
