#include "game.h"

void draw_to_window(t_my_game* game)
{
    int i = 0;

    mlx_destroy_image(game->co, game->img);
    game->img = mlx_new_image(game->co, WIDTH, HEIGHT);
    //draw_map(game);
    check_intersections(game);
    //draw_square(game->img, 255 , game->player.px, game->player.py, 8);
    // ft_cast(game, 255 << 16);
    mlx_put_image_to_window(game->co, game->win, game->img, 0, 0);
}

int game_key_hook(int keycode, t_my_game* game)
{
   double rotation, forward_steps, right_steps;
    double angle;

    rotation = 0;
    forward_steps = 0;
    right_steps = 0;
    if(keycode == XK_Escape)
       free_game(game, game->old_game);
    if(keycode == XK_a)
    {
        right_steps = 5;
    }
    if(keycode == XK_d)
    {
        right_steps = -5;
    }
    if(keycode == XK_Left)
        rotation = -5;
    if(keycode == XK_Right)
        rotation  = 5;
    if(keycode == XK_s || keycode == XK_Down)
        forward_steps = -5;
    if(keycode == XK_w || keycode == XK_Up)
        forward_steps = 5;
   
    game->player.rot = normalize_angle(game->player.rot + rotation * (pi / 180));
    game->player.ray_angle_start = normalize_angle(game->player.rot - (game->player.fov / 2));

    //angle = normalize_angle((pi / 2) - game->player.rot);
    angle = normalize_angle((3 * pi / 2) + game->player.rot);
    game->player.py += round(right_steps * sin(angle));
    game->player.px += round(right_steps* cos(angle));
    if(!check_wall(game, game->player.px + forward_steps * (cos(game->player.rot)), game->player.py + (forward_steps ) * (sin(game->player.rot))))
    {
        game->player.py += round((forward_steps ) * sin(game->player.rot));
        game->player.px += round(forward_steps * cos(game->player.rot));
    }
    // printf("player x:%d\n", game->player.px);
    // printf("player y:%d\n", game->player.py);

    draw_to_window(game);
    
}

void ft_execution(t_my_game* game)
{
    if(cub_init(game))
        return ;
    draw_to_window(game);
    mlx_hook(game->win,2, KeyPressMask, game_key_hook, game);
    mlx_loop(game->co);
}