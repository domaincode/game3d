

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

void	validate_map(t_map *map)
{
	if (map->map == NULL)
	{
		printf("Error: The map is missing.\n");
		exit(1);
	}
	else if(!validate_elements(map->map))
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

void	validate_field(t_field *field)
{
	validate_texture(field->no_tex.path, "NO texture");
	validate_texture(field->so_tex.path, "SO texture");
	validate_texture(field->we_tex.path, "WE texture");
	validate_texture(field->ea_tex.path, "EA texture");
	validate_color(&field->floor, "floor color");
	validate_color(&field->ceilling, "ceilling color");
	validate_map(field->map);
	
}

