#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include <stdlib.h>
# include "../cube.h"
# include "../external_outils/libft/libft.h"
# include "../external_outils/get_next_line/get_next_line.h"

void    player_map(t_map **map, int i);
void    parsing(t_map *map, char **av);
void    map_dimension(t_map **map, int i);
void    read_map(t_map **map, char **av);
void    cardinal_directions(t_map **map, int *s);
void    fill_struct(t_directions **dir, char *crdl, int index);
void    map_parsing(t_map **map);
int     ea_and_colors(char *str, t_directions *dir, int *s, int i);
int     ft_is_space(char c);
char    *ft_dup(char *str);
int     skipp_spaces(char *str, char to_find);
void    check_cardinal(t_directions *dir);
void    rgb_parse(char *str);
void    put_error(char *str);
int     str_lenght(char **str);
void    ft_free(char **str);
int     ft_is_player(char c);
int     ft_is_valid(char c);
long long    ft_condition(char *str, int i);

#endif
