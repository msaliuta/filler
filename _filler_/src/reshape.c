/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshape.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:03:13 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/12 01:20:26 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reshape(t_piece *piece)
{
	int		i;
	int		j;
	int		end_x;
	int		end_y;
	char	**buf;

	start_end_x(piece, &end_x);
	start_end_y(piece, &end_y);
	if (end_x - piece->start_x + 1 != piece->x ||
		end_y - piece->start_y + 1 != piece->y)
	{
		buf = piece->array;
		piece->x = end_x - piece->start_x + 1;
		piece->y = end_y - piece->start_y + 1;
		piece->array = ft_chartable(piece->x, piece->y);
		i = -1;
		while (++i < piece->x)
		{
			j = -1;
			while (++j < piece->y)
				piece->array[i][j] =
					buf[i + piece->start_x][j + piece->start_y];
		}
		ft_arrclr(buf);
	}
}
