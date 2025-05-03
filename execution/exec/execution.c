/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:11:03 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 18:11:08 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	game_key_hook_confg1(t_my_game *game, double x, double y)
{
	if (!check_wall2(game, x, y))
	{
		game->player.px = round(x);
		game->player.py = round(y);
	}
	else if (!check_wall2(game, x, game->player.py))
		game->player.px = round(x);
	else if (!check_wall2(game, game->player.px, y))
		game->player.py = round(y);
}

void	game_key_hook_confg(t_my_game *game, double f_steps, double r_steps, double rot)
{
	double	angle;
	double		x;
	double		y;

	game->player.rot = normalize_angle(game->player.rot + rot * (PI / 180));
	game->player.ray_angle_start = normalize_angle(game->player.rot
			- (game->player.fov / 2));
	if (r_steps)
	{
		angle = normalize_angle(game->player.rot - (PI / 2));
		//round
		x = round(game->player.px + r_steps * cos(angle));
		y = round(game->player.py + r_steps * sin(angle));
		game_key_hook_confg1(game, x, y);
	}
	else
	{
		x = round(game->player.px + f_steps * cos(game->player.rot));
		y = round(game->player.py + f_steps * sin(game->player.rot));
		game_key_hook_confg1(game, x, y);
	}
}

int	draw_to_window(t_my_game *game)
{
	game_key_hook_confg(game, game->forward_steps, game->right_steps, game->rotation);
	mlx_destroy_image(game->co, game->img);
	game->img = mlx_new_image(game->co, WIDTH, HEIGHT);
	check_intersections(game);
	map_to_minimap(game, game->player.px, game->player.py);
	mlx_put_image_to_window(game->co, game->win, game->img, 0, 0);
	return 0;
}

int	game_key_hook_press(int keycode, t_my_game *game)
{
	game->forward_steps = 0;
	game->rotation = 0;
	game->right_steps = 0;
	//printf("hello from key hook\n");
	if (keycode == XK_Escape)
		free_game(game, game->old_game);
	else if (keycode == XK_a)
		game->right_steps = 0.6;
	else if (keycode == XK_d)
		game->right_steps = -0.6;
	else if (keycode == XK_Left)
		game->rotation = -2;
	else if (keycode == XK_Right)
		game->rotation = 2;
	else if (keycode == XK_s || keycode == XK_Down)
		game->forward_steps = -0.7;
	else if (keycode == XK_w || keycode == XK_Up)
		game->forward_steps = 0.7;
		//draw_to_window(game);

}

int	game_key_hook_release(int keycode, t_my_game *game)
{
	if (keycode == XK_a)
		game->right_steps = 0;
	else if (keycode == XK_d)
		game->right_steps = 0;
	else if (keycode == XK_Left)
		game->rotation = 0;
	else if (keycode == XK_Right)
		game->rotation = 0;
	else if (keycode == XK_s || keycode == XK_Down)
		game->forward_steps = 0;
	else if (keycode == XK_w || keycode == XK_Up)
		game->forward_steps = 0;

}

void	ft_execution(t_my_game *game)
{
	if (cub_init(game))
		return ;
	draw_to_window(game);
	mlx_key_hook(game->win, game_key_hook_release, game);
	mlx_hook(game->win, 2, KeyPressMask, game_key_hook_press, game);
	mlx_loop_hook(game->co, draw_to_window, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, free_game, game);
	mlx_loop(game->co);
}
