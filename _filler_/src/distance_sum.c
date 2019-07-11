/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:08:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 03:11:57 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		distance_sum(t_game *game, int *sum, int i, int j)
{
	int dist_sum;
	int n;
	int m;

	dist_sum = 0;
	n = -1;
	while (++n < game->piece.x)
	{
		m = -1;
		while (++m < game->piece.y)
		{
			if (game->piece.array[n][m] == '*')
			{
				if (ft_tolower(game->map.array[i + n][j + m]) == game->me)
					*sum += 1;
				else if (ft_tolower(game->map.array[i + n][j + m]) ==
					game->opponent)
					*sum += 2;
				dist_sum += game->map.int_array[i + n][j + m];
			}
		}
	}
	return (dist_sum);
}
