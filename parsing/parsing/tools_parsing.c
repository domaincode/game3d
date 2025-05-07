#include "../includes/parse_map.h"
#include "../libs/libft/libft.h"

void skip_chars(char **line)
{
	while(**line && **line != ',')
		(*line)++;
	(*line)++;
}

void clean_spaces(char *line) {
    int i = 0;
    int j = 0;
    int in_word = 0;

    while (line[j] && (line[j] == ' ' || line[j] == '\t')) {
        j++;
    }
    while (line[j]) {
        if (line[j] == ' ' || line[j] == '\t') {
            if (in_word) {
                line[i++] = ' ';
                in_word = 0;
            }
        } else {
            line[i++] = line[j];
            in_word = 1;
        }
        j++;
    }
    if (i > 0 && line[i - 1] == ' ') {
        i--;
    }
    line[i] = '\0';
}
int		validate_extension(char *file, char *extension)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(extension);
	if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
		return (1);
	else
		return (0);
}

int	validate_init_pos(t_map **map)
{
	int i = 0 ;
	int j;
	int start_pos =0;
	while ((*map)->map[i])
	{
		j = 0;
		while((*map)->map[i][j])
		{
			if (ft_strchr("NEWS", (*map)->map[i][j]))
			{
				(*map)->x= j + 1;
				(*map)->y= i + 1;
				(*map)->direction = (*map)->map[i][j];
				start_pos += 1;

			}
			j++;
		}
		i++;
	}
	if(start_pos != 1 || start_pos == 0)
		return(0);
	return(1);
}

int	validate_elements(char **map)
{
	int i = 0 ;
	int j;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (!ft_strchr("NEWS01 \n", map[i][j]))
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}
int map_height(char **map)
{
    int height = 0;

    while (map[height] != NULL)
        height++;
    return height;
}

int validate_border(char **map)
{
    int i = 0;
    int j;

    while (map[0][i] != '\0')
    {
        if (map[0][i] != '1' && map[0][i] != ' ')
        {
            printf("Error: The map is not enclosed. Top row is invalid at column %d.\n", i);
            return (0);
        }
        i++;
    }

    i = 0;
    while (map[map_height(map) - 1][i] != '\0')
    {
        if (map[map_height(map) - 1][i] != '1' && map[map_height(map) - 1][i] != ' ')
        {
            printf("Error: The map is not enclosed. Bottom row is invalid at column %d.\n", i);
            return (0);
        }
        i++;
    }

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] == ' ')
            j++;
        if (map[i][j] != '1')
        {
            printf("Error: The map is not enclosed. Left border is invalid at row %d.\n", i);
            return (0);
        }

        j = strlen(map[i]) - 1;
        while (j >= 0 && map[i][j] == ' ')
            j--;
        if (map[i][j] != '1')
        {
            printf("Error: The map is not enclosed. Right border is invalid at row %d.\n", i);
            return (0);
        }

        i++;
    }

    return (1);
}