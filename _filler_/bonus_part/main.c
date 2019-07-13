/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:29:43 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:09:56 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		main(void)
{
	char		*line;
	t_visual	*v;

	v = ft_memalloc(sizeof(t_visual));
	read_p(v);
	while (1)
	{
		if (LINES * COLS != v->term_size)
			size_check(v, line);
		get_next_line(0, &line);
		if (v->m_heigth == 0 && ft_strstr(line, "Plateau"))
			init_wins(line, v);
		if (ft_strstr(line, "0123456789"))
		{
			show_map(v);
			show_scale(v->scale, v->p1_points, v->p2_points);
		}
		if (ft_strstr(line, "== X"))
			break ;
		ft_strdel(&line);
		usleep(-100 * (v->m_heigth - 100));
	}
	show_winner(v->p1_points, v->p2_points, v);
	over(v);
	return (0);
}
