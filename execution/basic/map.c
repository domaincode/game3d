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
                colors = color(0, 0, 0);
            else if(game->map.data[i][j])
                colors = color(255, 255, 255);
            draw_square(game->map_img, j * TILE_SIZE, i * TILE_SIZE, colors);
            j++;
        }
        i++;
    }
}


void map_to_minimap(t_my_game* game, int px, int py)
{
    int x_start, y_start, x_end, y_end;
    int offset;
    int y, x;
    y = x = 0;
    y_start = py - 60;
    x_end = px + 60;
    y_end = py + 60;
    draw_map(game);
    draw_player(game->img, 60, 60, 255);
    //exit(0);
    while(y_start < y_end)
    {
        x_start = px - 60;
        x = 0;
        //printf("hello\n");
        while(x_start < x_end)
        {
            //printf("22222222222222222222222\n");
            offset = get_pixel(game->map_img, x_start, y_start);
            my_pixel_put(game->img, x, y, *(int* )(game->map_img->data + offset));
            x++;
            x_start++;
        }
        y_start++;
        y++;
    }
}