/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:31:49 by osamoile          #+#    #+#             */
/*   Updated: 2019/07/12 03:45:30 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_piece(t_game *game, int *put_x, int *put_y)
{
	int i;
	int j;
	int sum;
	int dist_min;

	dist_min = 10000;
	*put_x = 0;
	*put_y = 0;
	i = -1;
	while (++i < game->map.x)
	{
		j = -1;
		while (++j < game->map.y)
		{
			sum = 0;
			if (i + game->piece.x <= game->map.x &&
			j + game->piece.y <= game->map.y &&
			distance_sum(game, &sum, i, j) < dist_min && sum == 1)
			{
				*put_x = i;
				*put_y = j;
				dist_min = distance_sum(game, &sum, i, j);
			}
		}
	}
}
