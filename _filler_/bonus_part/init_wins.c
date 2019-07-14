/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:02:17 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 14:53:45 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_wins(char *line, t_visual *v)
{
	setlocale(LC_ALL, "");
	initscr();
	use_default_colors();
	if (can_change_color() && COLORS >= 16)
        init_color(BRIGHT_WHITE, 1000,1000,1000);
	curs_set(0);
	v->term_size = LINES * COLS;
	read_sizes(line, v);
	refresh();
	v->map = newwin(v->m_heigth + 2, (v->m_width + 2) * 2, 0, 0);
	/*v->scale = newwin(5, 2 * SCALE_LEN + 4,
		v->m_heigth / 2 - 1, (v->m_width + 2) * 2 + 10);*/
	mvwaddstr(v->scale, 1, LBL_IND - ft_strlen(v->p1_name), v->p1_name);
	mvwaddstr(v->scale, 1,
		SCALE_LEN * 2 - LBL_IND - ft_strlen(v->p2_name), v->p2_name);
	box(v->map, 0, 0);
	//box(v->scale, 0, 0);
	wrefresh(v->scale);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
}
