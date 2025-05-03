/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:55:50 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 12:55:54 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	check_wall2(t_my_game *game, double x, double y)
{
	int	rows;
	int rows2;
	int	cols;
	int cols2;

	rows = (y / TILE_SIZE);
	cols = (x / TILE_SIZE);
	// rows2 = (round(y) / TILE_SIZE);
	// cols2 = (round(x) / TILE_SIZE);
	
	if ( game->map.data[rows][cols] == '1')
		return (1);
	// else if(game->map.data[rows2][cols] == '1' || game->map.data[rows][cols2] == '1')
	// 	return 1;
	return (0);
}

int	check_wall(t_my_game *game, int x, int y)
{
	int	rows;
	int	cols;

	rows = (y / TILE_SIZE);
	cols = (x / TILE_SIZE);
	//be carfulel protect ??
	if (game->map.data[rows][cols] == '1')
		return (1);
	return (0);
}
