#include "../game.h"

void map_configuration(t_my_game* game, char** data)
{
    int y, x;

    y = 0;
    game->map.rows = 0;
    game->map.cols = 0;

    while(data[y])
    {
        x = strlen(data[y]);
        if(game->map.cols < x)
            game->map.cols = x;
        y++;
    }
    game->map.rows = y;
    game->map.x_max = game->map.cols * TILE_SIZE;
    game->map.y_max = y * TILE_SIZE;

}