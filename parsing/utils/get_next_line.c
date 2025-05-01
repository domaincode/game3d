/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:32:38 by hchouai           #+#    #+#             */
/*   Updated: 2025/04/24 02:25:40 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*set_recub3dder(char *line_buffer)
{
	ssize_t	i;
	char	*recub3dder;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	recub3dder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*recub3dder == 0)
	{
		free (recub3dder);
		return (NULL);
	}
	line_buffer[i + 1] = '\0';
	return (recub3dder);
}

char	*fill_line_buffer(int fd, char *recub3dder, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (recub3dder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!recub3dder)
			recub3dder = (ft_strdup(""));
		tmp = recub3dder;
		recub3dder = ft_strjoin(tmp, buffer);
		free (tmp);
		if (ft_strchr(buffer, 10))
			break ;
	}
	return (recub3dder);
}

char	*get_next_line(int fd)
{
	static char	*recub3dder;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(recub3dder);
		free(buffer);
		recub3dder = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, recub3dder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	recub3dder = set_recub3dder(line);
	return (line);
}
