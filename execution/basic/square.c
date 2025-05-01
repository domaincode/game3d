#include "../game.h"

void draw_square(t_img* image, int posx, int posy, int color)
{
   int i, j;

   i = posy;

    while(i < posy + MAP_SIZE)
    {
        j = posx;
        while(j < posx + MAP_SIZE )
        {
            my_pixel_put(image, j, i , color);
            j++;
        }
        i++;
    }
}


void draw_player(t_img* image, int posx, int posy, int color)
{
   int i, j;

   i = posy;

    while(i < posy + PLAYER_SIZE)
    {
        j = posx;
        while(j < posx + PLAYER_SIZE)
        {
            my_pixel_put(image, j, i , color);
            j++;
        }
        i++;
    }
}