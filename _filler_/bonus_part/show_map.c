/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:06:21 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 19:28:41 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	show_maps(t_visual *vis)
{
	int		i;
	char	*line;

	vis->score1 = 0;
	vis->score2 = 0;
	i = -1;
	while (++i < vis->h)
	{
		get_next_line(0, &line);
		print_line(line, i, vis);
		ft_strdel(&line);
	}
	wrefresh(vis->maps);
}
