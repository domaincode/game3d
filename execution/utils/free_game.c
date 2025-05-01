#include "../game.h"

int free_game(t_my_game* game, t_game* old_game)
{
    int i;

    i = 0;
    mlx_destroy_image(game->co, game->img);

    mlx_destroy_image(game->co, game->north);
    mlx_destroy_image(game->co, game->south);
    mlx_destroy_image(game->co, game->west);
    mlx_destroy_image(game->co, game->east);

    mlx_destroy_window(game->co, game->win);
    mlx_destroy_display(game->co);
    free(game->co);
    while(game->map.data[i])
        free(game->map.data[i++]);
    free(game->map.data);
    // free(old_game->field->map);
    // free(old_game->field);
    // free(old_game);
    printf("Exit\n");
    exit(0);
}