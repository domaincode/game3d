/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:26:20 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/03 19:26:22 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ft_copy(t_my_game *my_game, t_game *game)
{
	my_game->old_game = game;
	my_game->map.data = game->field->map->map;
	my_game->floor_color = color(game->field->floor.r, game->field->floor.g,
			game->field->floor.b);
	my_game->ceiling_color = color(game->field->ceilling.r,
			game->field->ceilling.g, game->field->ceilling.b);
	my_game->textures.north = game->field->no_tex.path;
	my_game->textures.south = game->field->so_tex.path;
	my_game->textures.west = game->field->we_tex.path;
	my_game->textures.east = game->field->ea_tex.path;
}
