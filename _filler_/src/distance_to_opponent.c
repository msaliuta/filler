/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_opponent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:31:49 by osamoile          #+#    #+#             */
/*   Updated: 2019/07/12 01:19:52 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		abs1(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	distance_to_opponent(t_map map, char opponent)
{
	int		i;
	int		j;
	int		n;
	int		m;

	i = -1;
	while (++i < map.x)
	{
		j = -1;
		while (++j < map.y)
		{
			map.int_array[i][j] = 10000;
			n = -1;
			while (++n < map.x)
			{
				m = -1;
				while (++m < map.y)
				{
					if (ft_tolower(map.array[n][m]) == opponent &&
						abs1(n - i) + abs1(m - j) < map.int_array[i][j])
						map.int_array[i][j] = abs1(n - i) + abs1(m - j);
				}
			}
		}
	}
}
