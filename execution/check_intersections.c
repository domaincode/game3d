#include "game.h"
#include "math.h"

void choose_texture(t_my_game* game, int indice)
{
    if(indice == 1)
    {
        if(game->player.ray_angle >= 0 && game->player.ray_angle <= pi)
            game->test = game->south;
        else
            game->test = game->north;
    }
    else
    {
        if(game->player.ray_angle >= (pi / 2) && game->player.ray_angle <= (3 * pi / 2))
            game->test = game->west;
        else
            game->test = game->east;
    }
}

double check_horizontal(t_my_game* game, double distance_to_wall, int* texture_x, int* indice)
{
    double ay, ax, YA;
    double ray_angle;

    ray_angle = game->player.ray_angle;
    distance_to_wall = -1;
    facing_up(game, &ay, &YA, ray_angle);
    ax = (((ay - game->player.py) / tan(ray_angle)) + game->player.px);
    while(ax >= 0 && ay >= 0 && ay < game->map.y_max && ax < game->map.x_max)
    {
        if(check_wall(game, ax, ay))
        {
            *indice = 1;
            *texture_x = ax;
            distance_to_wall = (ax - game->player.px) * cos(game->player.rot) + (ay - game->player.py) * sin(game->player.rot);
            break;
        }
        ax += YA / tan(ray_angle);
        ay += YA;
    }
    return (distance_to_wall);
}

double check_vertical(t_my_game* game, double distance_to_wall, int* texture_x, int* indice)
{
    double my_distance, ay, ax, XA;
    double ray_angle;

    ray_angle = game->player.ray_angle;
    facing_left(game, &ax, &XA, ray_angle);
    ay = ((ax - game->player.px) * tan(ray_angle)) + game->player.py;
    while(ax >= 0 && ay >= 0 && ay < game->map.y_max && ax < game->map.x_max)
    {
        if(check_wall(game, ax, ay))
        {
            my_distance = (ax - game->player.px) * cos(game->player.rot) + (ay - game->player.py) * sin(game->player.rot);
            if(distance_to_wall == -1 || distance_to_wall > my_distance)
            {
                *indice = 2;
                *texture_x = ay;
                return (my_distance);
            }
            break;
        }
        ay += XA * tan(ray_angle);
        ax += XA;
    }
    return (distance_to_wall);
}

void check_intersections(t_my_game* game)
{
    double projected_wall_height, distance_to_wall, distance_to_screen;
    double angle_increment, ray_angle;
    int i, texture_x;
    int fix_value;
    int indice;
   
    i = 0;
    texture_x = 0;
    distance_to_wall = -1;
    distance_to_screen = WIDTH / (2 * tan(game->player.fov / 2));
    fix_value = TILE_SIZE * distance_to_screen;
    angle_increment = game->player.fov / RAYS;
    game->player.ray_angle = game->player.ray_angle_start;
    while(i < RAYS)
    {
         distance_to_wall = check_horizontal(game, distance_to_wall, &texture_x, &indice);
         distance_to_wall = check_vertical(game, distance_to_wall, &texture_x, &indice);
         choose_texture(game, indice);
          projected_wall_height = (fix_value / distance_to_wall);
        ft_textures(game, i * RES, texture_x % TILE_SIZE, projected_wall_height);
        //draw_line(game, texture_x, texture_y, 255 << 16);
        game->player.ray_angle  = normalize_angle(game->player.ray_angle + angle_increment);
        i++;
    }
}