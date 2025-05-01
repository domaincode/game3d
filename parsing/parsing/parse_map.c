
#include "../includes/parse_map.h"
#include "../libs/libft/libft.h"

void	parse_texture(char *line, t_texture *tex)
{
	line += 2;
	if(*line == ' ')
		line++;
	if (!tex->path)
		tex->path = ft_strdup(line);
}
void parse_resolution(t_field **field, t_map *map)
{
	(*field)->res.height = map->height * TILE_SIZE;
	(*field)->res.width = map->width * TILE_SIZE;

}

void	parse_color(char *line, t_color *color)
{
	line += 1;
	if(!ft_isdigit(line))
	{
		printf("ERROR: Enter a value between 0 & 255 : %s\n", line);
		exit(1) ;
	}
	if(*line == ' ')
		line++;
	color->r = ft_atoi(line);
	skip_chars(&line);
	color->g = ft_atoi(line);
	skip_chars(&line);
	color->b = ft_atoi(line);
}

void	parse_data(char *line, t_field **field)
{
	if (!line)
		return ;
	else if (!ft_strncmp(line, "NO", 2))
		parse_texture(line, &(*field)->no_tex);
	else if (!ft_strncmp(line, "SO", 2))
		parse_texture(line, &(*field)->so_tex);
	else if (!ft_strncmp(line, "WE", 2))
		parse_texture(line, &(*field)->we_tex);
	else if (!ft_strncmp(line, "EA", 2))
		parse_texture(line, &(*field)->ea_tex);
	else if (!ft_strncmp(line, "F", 1))
		parse_color(line, &(*field)->floor);
	else if (!ft_strncmp(line, "C", 1))
		parse_color(line, &(*field)->ceilling);
	else if (ft_strcmp(line, "\n"))
	{
		printf("ERROR: Wrong elment %s\n", line);
		exit(1);
	}
	
}

void	parse_field(int fd, t_field **field)
{
	char	*line;
	int i;
	int height;
	i = 0;
    height = height_map(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_map(line))
		{
			clean_spaces(line);
			parse_data(line, field);
		}
		else
		{
			parse_map(fd, line, ((*field)->map), i, height);
			i++;

		}
		free(line);
		line = get_next_line(fd);
	}
	parse_resolution(field, (*field)->map);
	free(line);
}
int	is_map(char *line)
{
	while (*line == ' ')
        line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
        !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) ||
        !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
        return (0);
	while (*line)
	{
		if (!ft_strchr("01NSEW  ", *line))
			return (0);
		else
			return(1);
		line++;
	}
		return (1);
}

int	height_map(int fd)
{
    char *line;
    int height = 0;

    while ((line = get_next_line(fd)))
    {
        if (is_map(line))
            height++;
        free(line);
    }
	lseek(fd, 0, SEEK_SET);
	if (fd < 0)
    {
        perror("Error: Failed to reopen file");
        exit(EXIT_FAILURE);
    }
    return height;
}

char	*cpy_map(char *line)
{
	return(ft_strdup(line));
}

size_t	get_width(int fd, char *line)
{
	size_t	max_length;
	size_t	length;
	int		i;

	max_length = 0;
	while (line)
	{
		length = 0;
		i = 0;
		while (line[i])
		{
            length++;
            i++;
		}
		if (length > max_length)
			max_length = length;
		line = get_next_line(fd);
	}
    lseek(fd, 0, SEEK_SET);
	if (fd < 0)
    {
        perror("Error: Failed to reopen file");
        exit(EXIT_FAILURE);
    }
	return (max_length);
}

void	parse_map(int fd, char *line, t_map *map, int i, int height)
{
	if (i == 0)
    {
        map->height = height;
        map->width = get_width(fd, line);
        map->map = malloc(sizeof(char *) * (map->height + 1));
        if (!map->map)
        {
            perror("Error: malloc failed");
            exit(EXIT_FAILURE);
        }
		  map->map[map->height] = NULL;
    }
    map->map[i] = cpy_map(line);
}
