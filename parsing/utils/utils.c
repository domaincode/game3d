
#include "../includes/utils.h"
#include "../libs/libft/libft.h"

ssize_t	ft_strlen1(char *s)
{
	ssize_t	i;
	
	if(!s)
		return(0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	init_field(t_field **field)
{
	if (!field)
		return;
	(*field)->res.width = 0;
	(*field)->res.height = 0;
	(*field)->no_tex.path = NULL;
	(*field)->so_tex.path = NULL;
	(*field)->we_tex.path = NULL;
	(*field)->ea_tex.path = NULL;
	(*field)->floor.r = -1;
	(*field)->floor.g = -1;
	(*field)->floor.b = -1;
	(*field)->ceilling.r = -1;
	(*field)->ceilling.g = -1;
	(*field)->ceilling.b = -1;
	(*field)->map->width = 0;
	(*field)->map->height = 0;
	
}

void	check_errors(char *file, int fd)
{
	int	len;

	len = ft_strlen(file) - 1;
	while (file[len] != '.')
		len--;
	if (ft_strncmp(file + len, ".cub", 5))
	{
		perror("invalid Extension");
		exit(0);
	}
	if (fd < 0)
	{
		perror ("Error");
		exit(0);
	}
}