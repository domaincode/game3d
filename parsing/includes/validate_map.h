#ifndef CHECK_MAP_H 
# define CHECK_MAP_H

#include "cub3d.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"

void	validate_field(t_field *field);
int		validate_extension(char *file, char *extension);
int     validate_init_pos(t_map **map);
int	    validate_elements(char **map);
int	    validate_border(char **map);
#endif