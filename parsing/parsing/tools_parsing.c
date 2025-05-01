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
			if (!ft_strchr("NEWS01\n", map[i][j]))
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

int	validate_border(char **map)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i++] != '1')
			return (0);
	}
	while ((map[j]))
	{
		len = ft_strlen1(map[j]);
		if (map[j][0] != '1' || map[j][len - 1] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (map[j - 1][i])
	{
		if (map[j - 1][i++] != '1')
			return (0);
	}
	return (1);
}