#include "../game.h"

void draw_line(t_my_game* game, int x_end, int y_end, int color)
{
    float dx, dy, steps, xinc, yinc;
    int i;

    i = 0;
    dx = x_end - game->player.px;
    dy = y_end - game->player.py;
    steps = fmax(fabs(dx), fabs(dy));
    xinc = dx / steps;
    yinc = dy / steps;
    dx = game->player.px;
    dy = game->player.py;
    while(i < steps)
    {
       my_pixel_put(game->img, dx, dy, color);
        dx += xinc;
        dy += yinc;
        i++;
    }
}