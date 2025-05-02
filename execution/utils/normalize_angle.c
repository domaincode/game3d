/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:07:26 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 13:07:28 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

double	normalize_angle(double angle)
{
	if (angle > 2 * PI)
		return (angle - 2 * PI);
	else if (angle <= 0)
		return (angle + 2 * PI);
	return (angle);
}
