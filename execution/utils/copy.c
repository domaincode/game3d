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

void	ft_copy(t_my_game *my_game, t_directions	*direction)
{
	my_game->direction = direction;
	my_game->map.data = direction->map->map;
	my_game->floor_color = direction->f;
	my_game->ceiling_color = direction->c;
	my_game->textures.north = direction->no;
	my_game->textures.south = direction->so;
	my_game->textures.west = direction->we;
	my_game->textures.east = direction->ea;
}
