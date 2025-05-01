#include "../game.h"

void clor_ceiling_floor(t_my_game* game, int y_start, int y_end, int x_start, int color)
{
    int y, x, x_end;

    x_end = x_start + RES;
    y = y_start;
    while(y < y_end)
    {
        x = x_start;
        while(x < x_end)
        {
            my_pixel_put(game->img, x, y, color);
            x++;
        }
        y++;
    }
}