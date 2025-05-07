#ifndef UTILS_H 
# define UTILS_H

#include "cub3d.h"
#include <stdio.h>
#include "structs.h"

//char	**cpy_map(char **tmp, char **map);
ssize_t	ft_strlen1(char *s);
void	init_field(t_field **field);
void	check_errors(char *file, int fd);
//int     handle_close(void *param);

#endif