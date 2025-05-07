
#include "../includes/cub3d.h"
#include "../includes/utils.h"



void free_color(t_color *color)
{
    if (color)
    {
        color->r = -1;
        color->g = -1;
        color->b = -1;
    }
}

void free_map(t_map *map)
{
    if (map)
    {
        int i = 0;
        // Free each row of the map
        while ( i < map->height)
        {
            if (map->map[i])
                free(map->map[i]);
            i++;
        }
        
        if (map->map)
            free(map->map);
        
        map->map = NULL;
    }
}

void free_texture(t_texture *tex)
{
    if (tex && tex->path)
    {
        free(tex->path);
        tex->path = NULL;
    }
}

void free_field(t_field *field)
{
    if (field)
    {
        free_texture(&field->no_tex);
        free_texture(&field->so_tex);
        free_texture(&field->we_tex);
        free_texture(&field->ea_tex);
        free_color(&field->floor);
        free_color(&field->ceilling);
    }
}

void free_all(t_field *field, t_map *map)
{
    free_map(map);
    free_field(field);
}


// int main(int ac, char **av)
// {
//     t_game *game;
//     int fd;

//     if (ac != 2)
//     {
//         printf("Please provide a map!");
//         return (1);
//     }
//     fd = open(av[1], O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error\n Failed to open file %s.\n", av[1]);
//         exit(1);
//     }
//     check_errors(av[1], fd);
//     game = malloc(sizeof(t_game));
//     if (!game)
//     {
//     printf("Error: Memory allocation failed for game.\n");
//     exit(1);
//     }
//     game->field = malloc(sizeof(t_field));
//     game->field->map = malloc(sizeof(t_map));
//     printf("DEBUG: map pointer = %p\n", game->field->map);
//     printf("DEBUG: map->map pointer = %p\n", game->field->map->map);

//     init_field(&(game->field));
//     parse_field(fd, &game->field);
//     validate_field(game->field);

//     printf("Parsing completed successfully!\n");
//     printf("Field data:\n");
//     printf("North texture: %s\n", game->field->no_tex.path);
//     printf("South texture: %s\n", game->field->so_tex.path);
//     printf("West texture: %s\n", game->field->we_tex.path);
//     printf("East texture: %s\n", game->field->ea_tex.path);
//     printf("Floor color: %d,%d,%d\n", game->field->floor.r, game->field->floor.g, game->field->floor.b);
//     printf("Ceiling color: %d,%d,%d\n", game->field->ceilling.r, game->field->ceilling.g, game->field->ceilling.b);
//     free_all(game->field, game->field->map);
//     free(game);

//     close(fd);
//     return (0);
// }