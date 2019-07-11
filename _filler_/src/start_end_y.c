/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:01:27 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/12 01:20:13 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	start_end_y(t_piece *piece, int *end_y)
{
	int	i;
	int j;
	int	y_found;

	i = -1;
	y_found = 0;
	while (++i < piece->y)
	{
		j = -1;
		while (++j < piece->x)
		{
			if (piece->array[j][i] == '*')
			{
				*end_y = i;
				if (!y_found)
				{
					piece->start_y = i;
					y_found = 1;
				}
			}
		}
	}
}
