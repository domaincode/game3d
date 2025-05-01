/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:58:47 by hchouai           #+#    #+#             */
/*   Updated: 2025/02/17 16:14:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strchr( char *s, int c);
char	*ft_strdup( char *src);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_line_buffer(int fd, char *recub3dder, char *buffer);
char	*set_recub3dder(char *line_buffer);
char	*get_next_line(int fd);

#endif
