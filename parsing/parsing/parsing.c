
#include "parsing.h"

int	str_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	s_directions_initialization(t_map **map)
{
	(*map)->directions->f = -1;
	(*map)->directions->c = -1;
	(*map)->directions->ea = NULL;
	(*map)->directions->we = NULL;
	(*map)->directions->no = NULL;
	(*map)->directions->so = NULL;
}
void	fill_new_map(t_map **map, int s)
{
    char	**new;
    int		i;

    // Allocate memory for the new map
    new = malloc(sizeof(char *) * ((*map)->m_y + 1));
    if (!new)
        return; // Handle allocation failure

    // Copy existing map lines to the new map
    i = 0;
    while (i < (*map)->m_y && (*map)->map[s])
    {
        new[i] = ft_strdup((*map)->map[s]);
        if (!new[i])
        {
            // Free already allocated memory in case of failure
            while (i > 0)
                free(new[--i]);
            free(new);
            return;
        }
        s++;
        i++;
    }

    // Null-terminate the new map array
    new[i] = NULL;

    // Free the old map
    ft_free((*map)->map);

    // Replace the old map with the new map
    (*map)->map = new;
}


void	parsing(t_map *map, char **av)
{
	int	s;

	s = 0;
	read_map(&map, av);
	s_directions_initialization(&map);
	cardinal_directions(&map, &s);
	player_map(&map, s);
	map_dimension(&map, s);
	fill_new_map(&map, s);
	map_parsing(&map);   
}
