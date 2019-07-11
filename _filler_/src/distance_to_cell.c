/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:18:41 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 03:19:50 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		distance_to_cell(t_map map, char me, int x, int y)
{
	int		i;
	int		j;
	int		min;

	min = 10000;
	i = -1;
	while (++i < map.x)
	{
		j = -1;
		while (++j < map.y)
		{
			map.int_array[i][j] = ft_abs(x - i) + ft_abs(y - j);
			if (ft_tolower(map.array[i][j]) == me && map.int_array[i][j] < min)
				min = map.int_array[i][j];
		}
	}
	return (min);
}
