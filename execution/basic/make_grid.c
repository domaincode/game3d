#include "../game.h"

int make_grid(t_img* img, int color)
{
    int x, y;

    y = 0;
    while(y < img->height)
    {
        x = 0;
        while(x < img->width)
        {
            if(x % 8 && y % 8)
                my_pixel_put(img, x, y, color);
            else
                my_pixel_put(img, x, y, 255 << 16);
            x++;
        }
        y++;
    }
    return 0;
}