/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:29:43 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		main(void)
{
	char		*line;
	t_visual	*vis;

	vis = ft_memalloc(sizeof(t_visual));
	read_p(vis);
	while (1)
	{
		get_next_line(0, &line);
		if (vis->h == 0 && ft_strstr(line, "Plateau"))
			init_wins(line, vis);
		if (ft_strstr(line, "0123456789"))
		{
			show_maps(vis);
			show_res_tab(vis->res_tab, vis->score1, vis->score2);
		}
		if (ft_strstr(line, "== X"))
			break ;
		ft_strdel(&line);
		usleep(-100 * (vis->h - 100));
	}
	winner(vis->score1, vis->score2, vis);
	return (0);
}
