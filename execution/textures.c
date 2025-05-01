#include "game.h"
void ft_textures_confg(double* offset_begin, double* offset_end, int projected_height)
{
    if(*offset_begin < 0)
        *offset_begin = 0;
    *offset_end = *offset_begin + projected_height;
    if(*offset_end > HEIGHT)
        *offset_end = HEIGHT;
}

void ft_textures(t_my_game* game, int projected_x_start, int texture_x, double projected_height)
{
    t_img* img_tmp;

    double offset_begin, offset_end, x, y;
    int texture_y;
    int offset;
    offset_begin = (HEIGHT / 2) - (projected_height / 2);
    ft_textures_confg(&offset_begin, &offset_end, projected_height);

    y = offset_begin;
    texture_y = 0;
    clor_ceiling_floor(game, 0, offset_begin, projected_x_start, game->ceiling_color);
    while(y < offset_end)
    {
        texture_y = (y  + ((projected_height / 2) - (HEIGHT / 2))) * (TILE_SIZE / projected_height);
        x = projected_x_start;
        while(x < projected_x_start + RES)
        {
            offset = get_pixel(game->test, texture_x, texture_y);
             my_pixel_put(game->img, x, y, *(int* )(game->test->data + offset));
            x++;
        }
        y++;
    }
    clor_ceiling_floor(game, offset_end, HEIGHT, projected_x_start, game->floor_color);
}