/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:07:34 by zchtaibi          #+#    #+#             */
/*   Updated: 2025/02/26 14:31:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupL(const char *s)
{
	char	*pt;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlenl(s);
	i = 0;
	pt = (char *)malloc((len_s + 1) * sizeof(char));
	if (pt == NULL)
		return (NULL);
	while (s && s[i])
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
