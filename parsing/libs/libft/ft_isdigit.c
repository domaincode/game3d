/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:24:41 by zchtaibi          #+#    #+#             */
/*   Updated: 2025/02/26 14:36:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *str)
{
	char	*temp;
	int		i;
	i = 0;
	temp = ft_strdupL(str);
	while (temp[i])
	{
		if ((temp[i] >= '0' && temp[i] <= '9') || temp[i] == ',' || temp[i] == ' ' || temp[i] == '\n')
			i++;
		else
		{
			free(temp);
			return(0);
		}
		
	}
	return (1);
}
