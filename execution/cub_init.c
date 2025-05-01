#include "game.h"

int cub_init(t_my_game* game)
{
    int k;
    int b;
    set_player_position(game);
   map_configuration(game, game->map.data);
    game->player.fov = 60 * (pi / 180);
    game->player.ray_angle_start = game->player.rot - (game->player.fov / 2);
    game->co = mlx_init();
    if(game->co == NULL)
    {
        printf("error in mlx_init()\n");
        exit(1);
    }
    game->win = mlx_new_window(game->co, WIDTH, HEIGHT, "WINDOW 1");
    game->img = mlx_new_image(game->co, WIDTH, HEIGHT);
    game->map_img = mlx_new_image(game->co, game->map.cols * MAP_SIZE, game->map.rows * MAP_SIZE);

    // game->north = game->south = game->east = game->west = mlx_new_image(game->co, TILE_SIZE, TILE_SIZE);
    // make_grid(game->north, 255 );
    game->north = mlx_xpm_file_to_image(game->co,game->textures.north, &b, &b);
    game->south = mlx_xpm_file_to_image(game->co,game->textures.south, &b, &b);
    game->west = mlx_xpm_file_to_image(game->co,game->textures.west, &b, &b);
    game->east = mlx_xpm_file_to_image(game->co,game->textures.east, &b, &b);
    //free textures paths
    free(game->textures.north);
    free(game->textures.south);
    free(game->textures.west);
     free(game->textures.east);

    if(!game->north || !game->south | !game->west || !game->east)
    {
        printf("error in cub_init\n");
        exit(1);
    }
    return 0;
}