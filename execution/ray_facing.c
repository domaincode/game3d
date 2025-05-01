#include "game.h"

void facing_up(t_my_game* game, double* ay, double* YA, double ray_angle)
{
    if(sin(ray_angle) < 0)
    {
        *YA = -TILE_SIZE;
        *ay = (game->player.py / TILE_SIZE) * TILE_SIZE - 0.001;
    }
    else
    {
        *YA = TILE_SIZE;
        *ay = (game->player.py / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
    }
}

void facing_left(t_my_game* game, double* ax, double* XA, double ray_angle)
 {
    if(cos(ray_angle) <= 0)
    {
        *XA = -TILE_SIZE;
        *ax = (game->player.px / TILE_SIZE) * TILE_SIZE - 0.001;
    }
    else
    {
        *XA = TILE_SIZE;
        *ax = (game->player.px / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
    }
 }