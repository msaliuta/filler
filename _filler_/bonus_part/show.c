/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:06:21 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 14:25:46 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	show_map(t_visual *v)
{
	int		i;
	char	*line;

	v->p1_points = 0;
	v->p2_points = 0;
	i = -1;
	while (++i < v->m_heigth)
	{
		get_next_line(0, &line);
		if ((int)ft_strlen(line) != v->m_width + 4)
			size_check(v, line);
		print_line(line, i, v);
		ft_strdel(&line);
	}
	wrefresh(v->map);
}

/*void	show_scale(WINDOW *scale, int p1, int p2)
{
	char	*n;
	int		i;
	int		percent;

	n = ft_itoa(p1);
	mvwaddstr(scale, 3, LBL_IND - ft_strlen(n) / 2, n);
	ft_strdel(&n);
	n = ft_itoa(p2);
	mvwaddstr(scale, 3, 2 * SCALE_LEN - LBL_IND - ft_strlen(n) / 2, n);
	ft_strdel(&n);
	percent = SCALE_LEN * p1 / (p1 + p2);
	i = 0;
	while (++i < percent)
		mvwaddstr(scale, 2, 2 * i, GREEN_LEAF);
	while (i++ < SCALE_LEN)
		mvwaddstr(scale, 2, 2 * i, RED_LEAF);
	wrefresh(scale);
}*/

/*void	show_winner(int p1, int p2, t_visual *v)
{
	char	*text;

	if (p1 > p2)
		text = ft_strjoin(v->p1_name, " WON!");
	else
		text = ft_strjoin(v->p2_name, " WON!");
	wattron(v->scale, A_BOLD | COLOR_PAIR(4));
	mvwaddstr(v->scale, 3, SCALE_LEN - ft_strlen(text) / 2, text);
	wrefresh(v->scale);
}*/
