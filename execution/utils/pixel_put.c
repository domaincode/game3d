#include "../game.h"

int color(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

void my_pixel_put(t_img* image, int x, int y, int color)
{
    int offset;
    if(x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
        return ;
    offset = x * 4 + y *image->size_line;
    *(int* )(image->data + offset) = color;
}

int get_pixel(t_img *image, int x, int y)
{
    int offset;

    offset = x * 4 + y * image->size_line;
    return (offset);
}