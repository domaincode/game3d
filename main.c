#include "./execution/game.h"
#include "./parsing/includes/cub3d.h"
 #include "./parsing/includes/utils.h"

int main(int ac, char **av)
{
    t_game *game;
    t_my_game my_game;
    int fd;

    if (ac != 2)
    {
        printf("Please provide a map!");
        return (1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n Failed to open file %s.\n", av[1]);
        exit(1);
    }
    check_errors(av[1], fd);
    game = malloc(sizeof(t_game));
    if (!game)
    {
    printf("Error: Memory allocation failed for game.\n");
    exit(1);
    }
    game->field = malloc(sizeof(t_field));
    game->field->map = malloc(sizeof(t_map));
    init_field(&(game->field));
    parse_field(fd, &game->field);
    validate_field(game->field);

    printf("Parsing completed successfully!\n");
    printf("Field data:\n");
    printf("North texture: %s\n", game->field->no_tex.path);
    printf("South texture: %s\n", game->field->so_tex.path);
    printf("West texture: %s\n", game->field->we_tex.path);
    printf("East texture: %s\n", game->field->ea_tex.path);
    printf("Floor color: %d,%d,%d\n", game->field->floor.r, game->field->floor.g, game->field->floor.b);
    printf("Ceiling color: %d,%d,%d\n", game->field->ceilling.r, game->field->ceilling.g, game->field->ceilling.b);
   
    
    ft_execution(&my_game, game);

    free(game->field->map);
    free(game->field);
    free(game);

    close(fd);
    return (0);
}