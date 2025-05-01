#include "../game.h"

double normalize_angle(double angle)
{
    if(angle > 2 * pi)
        return(angle - 2 * pi);
    else if(angle <= 0)
        return (angle + 2 * pi);
    return angle;
}