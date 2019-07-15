/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:05:50 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	print_line(char *line, int i, t_visual *vis)
{
	int	j;

	j = 3;
	while (++j < vis->w + 4)
	{
		if (line[j] == 'x')
			wattron(vis->maps, COLOR_PAIR(1));
		else if (line[j] == 'o')
			wattron(vis->maps, COLOR_PAIR(1));
		if (line[j] == 'O' || line[j] == 'o')
		{
			mvwaddstr(vis->maps, i + 1, 2 * j - 6, CAT);
			vis->score1++;
		}
		else if (line[j] == 'X' || line[j] == 'x')
		{
			mvwaddstr(vis->maps, i + 1, 2 * j - 6, MONKEY);
			vis->score2++;
		}
		else
			mvwaddstr(vis->maps, i + 1, 2 * j - 6, ". ");
		wattron(vis->maps, COLOR_PAIR(3));
	}
}
