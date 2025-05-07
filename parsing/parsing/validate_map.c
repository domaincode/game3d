

#include "../includes/parse_map.h"



void	validate_texture(char *texture_path, char *texture_name)
{
	int	fd;

	if (texture_path == 0)
	{
		printf("Error: The %s is missing\n", texture_name);
		exit(1);
	}
	if (!validate_extension(texture_path, ".xpm"))
	{
		printf("Error: The texture File %s should be in xpm extension\n", texture_name);
		exit(1);
	}
	if ((fd = open(texture_path, O_RDONLY)) == -1)
	{
		printf("Error: Could not open the texture's file %s : %s", texture_name, texture_path);
		exit(1);
	}
	if (close(fd) == -1)
	{
		printf("Error: Could not close file %s.\n", texture_path);
		exit(1);
	}
}

void	validate_color(t_color *color, char *element_name)
{
	if (color->r == -1)
	{
		printf("Error: The %s is missing.\n", element_name);
		exit(1);
	}
	else if (255 < color->r || 255 < color->g || 255 < color->b)
	{
		printf("Error: The RGB code for the %s is incorrect.\n", element_name);
		exit(1);
	}
}

int is_valid_neighbor(char c)
{
    return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int is_space_or_wall(char c)
{
    return (c == '1' || c == ' ');
}

int validate_zero_neighbors(char **map, int row, int col)
{
    // Check above
    if (row > 0 && !is_valid_neighbor(map[row - 1][col]) && !is_space_or_wall(map[row - 1][col]))
        return 0;
    // Check below
    if (map[row + 1] && !is_valid_neighbor(map[row + 1][col]) && !is_space_or_wall(map[row + 1][col]))
        return 0;
    // Check left
    if (col > 0 && !is_valid_neighbor(map[row][col - 1]) && !is_space_or_wall(map[row][col - 1]))
        return 0;
    // Check right
    if (map[row][col + 1] != '\0' && !is_valid_neighbor(map[row][col + 1]) && !is_space_or_wall(map[row][col + 1]))
        return 0;
    return 1;
}

int validate_map_enclosure(char **map)
{
    for (int row = 0; map[row] != NULL; row++)
    {
        for (int col = 0; map[row][col] != '\0'; col++)
        {
            if (map[row][col] == '0')
            {
                if (!validate_zero_neighbors(map, row, col))
                {
                    printf("Error: Map is not properly enclosed at row %d, column %d.\n", row + 1, col + 1);
                    return 0;
                }
            }
        }
    }
    return 1;
}

void validate_map(t_map *map)
{
    if (map->map == NULL)
    {
        printf("Error: The map is missing.\n");
        exit(1);
    }
    
    // Debugging: Print map lines to ensure map is correctly loaded
    // printf("DEBUG: Map content:\n");
	// int i = 0;
    // while (map->map[i] != NULL)
    // {
    //     printf("%s", map->map[i]);
	// 	i++;
    // }

    if (!validate_elements(map->map))
    {
        printf("Error: A not allowed element exists.\n");
        exit(1);
    }
    else if (!validate_border(map->map))
    {
        printf("Error: The map is not enclosed.\n");
        exit(1);
    }
    else if (!validate_init_pos(&map))
    {
        printf("Error: The map has 0 or more than 1 start position.\n");
        exit(1);
    }
}

void validate_field(t_field *field)
{
    validate_texture(field->no_tex.path, "NO texture");
    validate_texture(field->so_tex.path, "SO texture");
    validate_texture(field->we_tex.path, "WE texture");
    validate_texture(field->ea_tex.path, "EA texture");
    validate_color(&field->floor, "floor color");
    validate_color(&field->ceilling, "ceilling color");
    validate_map(field->map);
    if (!validate_map_enclosure(field->map->map))
    {
        printf("Error: The map contains improperly enclosed areas.\n");
        exit(1);
    }
}


