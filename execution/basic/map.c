#include "../game.h"

void draw_map(t_my_game* game)
{
    int i, j;
    int colors;

    i = 0;
    while(game->map.data[i])
    {
        j = 0;
        while(game->map.data[i][j])
        {
            if(game->map.data[i][j] == '1')
                colors = color(255, 255, 255);
            else if(game->map.data[i][j])
                colors = color(118, 105, 105);
            draw_square(game->img, colors, j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE - 1);
            j++;
        }
        i++;
    }
}