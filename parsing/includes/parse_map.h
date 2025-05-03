
#ifndef GET_MAP_H 
# define GET_MAP_H

#include "cub3d.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"


void parse_field(int fd, t_field **field);
int		is_map(char *line);
int height_map(int fd);
char *cpy_map(char *line);
size_t	get_width(int fd, char *line);
void	parse_map(int fd, char *line, t_map *map, int i, int height);
void skip_chars(char **line);
void clean_spaces(char *line);
#endif