/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 02:59:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 03:00:48 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	start_end_x(t_piece *piece, int *end_x)
{
	int i;
	int	x_found;

	i = -1;
	x_found = 0;
	while (++i < piece->x)
	{
		if (ft_strchr(piece->array[i], '*'))
		{
			*end_x = i;
			if (!x_found)
			{
				piece->start_x = i;
				x_found = 1;
			}
		}
	}
}
