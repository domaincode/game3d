#include "../game.h"

void draw_fov(t_my_game* game, int color)
{
    double rayangle;
    rayangle = game->player.rot - (game->player.fov / 2);
    draw_line(game, game->player.px + 100 * cos(rayangle), game->player.py + 100 * sin(rayangle), color);
    draw_line(game, game->player.px + 100 * cos(rayangle + game->player.fov), game->player.py + 100 * sin(rayangle + game->player.fov), color);
}

void ft_cast(t_my_game* game, int color)
{
    double rayangle, delta;

    int i;

    i = 0;
    rayangle = game->player.ray_angle_start;
    delta = game->player.fov / RAYS;
    while(i < RAYS)
    {
        draw_line(game, game->player.px + 50 * cos(rayangle), game->player.py + 50 * sin(rayangle), color);
        rayangle += delta;
        i++;
    }
}

