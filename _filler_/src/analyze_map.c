/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:31:49 by osamoile          #+#    #+#             */
/*   Updated: 2019/07/11 03:24:54 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	analyze_map(t_game *game)
{
	int		me_top;
	int		op_top;
	int		me_left;

	me_top = top(game->map, game->me);
	op_top = top(game->map, game->opponent);
	me_left = left(game->map, game->me);
	if (me_top > op_top)
	{
		if (!way_closed(game, me_top))
			distance_to_cell(game->map, game->me, 0, game->map.y - 1);
		else
			distance_to_cell(game->map, game->me, game->map.x - 1, 0);
	}
	else
		distance_to_cell(game->map, game->me, op_top - 1, 0);
	if (me_left <= 2 || game->map.x > 20)
		distance_to_opponent(game->map, game->opponent);
}
