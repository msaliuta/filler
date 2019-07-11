/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:18:41 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/12 01:19:41 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

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
			map.int_array[i][j] = abs(x - i) + abs(y - j);
			if (ft_tolower(map.array[i][j]) == me && map.int_array[i][j] < min)
				min = map.int_array[i][j];
		}
	}
	return (min);
}
