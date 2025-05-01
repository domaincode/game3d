#include "../game.h"

void draw_square(t_img* image, int color, int posx, int posy, int s)
{
   int i, j;

   i = posy;

    while(i < posy + s)
    {
        j = posx;
        while(j < posx + s )
        {
            my_pixel_put(image, j, i , color);
            j++;
        }
        i++;
    }
}