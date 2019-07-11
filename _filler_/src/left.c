/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:22:12 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 03:22:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		left(t_map map, char player)
{
	int		i;
	int		j;

	j = -1;
	while (++j < map.y)
	{
		i = -1;
		while (++i < map.x)
		{
			if (ft_tolower(map.array[i][j]) == player)
				return (j);
		}
	}
	return (0);
}
