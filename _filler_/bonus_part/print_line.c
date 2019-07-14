/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:05:50 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 14:35:58 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	print_line(char *line, int i, t_visual *v)
{
	int	j;

	j = 3;
	while (++j < v->m_width + 4)
	{
		line[j] == 'o' ? wattron(v->map, COLOR_PAIR(1)) : 0;
		(line[j] != 'o' & line[j] == 'x') ? wattron(v->map, COLOR_PAIR(2)) : 0;
		if (line[j] == 'O' || line[j] == 'o')
		{
			mvwaddstr(v->map, i + 1, 2 * j - 6, GREEN_LEAF);
			v->p1_points++;
		}
		else if (line[j] == 'X' || line[j] == 'x')
		{
			mvwaddstr(v->map, i + 1, 2 * j - 6, RED_LEAF);
			v->p2_points++;
		}
		else
			mvwaddch(v->map, i + 1, 2 * j - 6, line[j]);
		wattron(v->map, COLOR_PAIR(3));
	}
}
