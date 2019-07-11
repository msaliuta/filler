/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:23:33 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 20:44:35 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		way_closed(t_game *game, int me_top)
{
	int		i;

	i = -1;
	while (++i < me_top)
	{
		if (ft_tolower(game->map.array[i][game->map.y - 1]) == game->opponent)
			return (1);
	}
	return (0);
}
