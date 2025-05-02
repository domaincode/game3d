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

void	game_key_hook_confg1(t_my_game *game, int x, int y)
{
	if (!check_wall(game, x, y))
	{
		game->player.px = x;
		game->player.py = y;
	}
	else if (!check_wall(game, x, game->player.py))
		game->player.px = x;
	else if (!check_wall(game, game->player.px, y))
		game->player.py = y;
}

void	game_key_hook_confg(t_my_game *game, int f_steps, int r_steps, int rot)
{
	double	angle;
	int		x;
	int		y;

	game->player.rot = normalize_angle(game->player.rot + rot * (PI / 180));
	game->player.ray_angle_start = normalize_angle(game->player.rot
			- (game->player.fov / 2));
	if (r_steps)
	{
		angle = normalize_angle(game->player.rot - (PI / 2));
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

void	draw_to_window(t_my_game *game)
{
	mlx_destroy_image(game->co, game->img);
	game->img = mlx_new_image(game->co, WIDTH, HEIGHT);
	check_intersections(game);
	map_to_minimap(game, game->player.px, game->player.py);
	mlx_put_image_to_window(game->co, game->win, game->img, 0, 0);
}

int	game_key_hook(int keycode, t_my_game *game)
{
	double	angle;
	double	rotation;
	double	forward_steps;
	double	right_steps;

	rotation = 0;
	forward_steps = 0;
	right_steps = 0;
	if (keycode == XK_Escape)
		free_game(game, game->old_game);
	else if (keycode == XK_a)
		right_steps = 1.5;
	else if (keycode == XK_d)
		right_steps = -1.5;
	else if (keycode == XK_Left)
		rotation = -2;
	else if (keycode == XK_Right)
		rotation = 2;
	else if (keycode == XK_s || keycode == XK_Down)
		forward_steps = -5;
	else if (keycode == XK_w || keycode == XK_Up)
		forward_steps = 5;
	game_key_hook_confg(game, forward_steps, right_steps, rotation);
	draw_to_window(game);
}

void	ft_execution(t_my_game *game)
{
	if (cub_init(game))
		return ;
	draw_to_window(game);
	mlx_hook(game->win, 2, KeyPressMask, game_key_hook, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, free_game, game);
	mlx_loop(game->co);
}
