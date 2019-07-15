/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:02:17 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	init_pair(4, COLOR_CYAN, COLOR_WHITE);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
}

void	result_board(t_visual *vis)
{
	mvwaddstr(vis->res_tab, 1, 29, "RESULT BOARD");
	wattron(vis->res_tab, COLOR_PAIR(6));
	mvwaddstr(vis->res_tab, 3, SP, vis->p1);
	wattroff(vis->res_tab, COLOR_PAIR(6));
	wattron(vis->res_tab, COLOR_PAIR(2));
	mvwaddstr(vis->res_tab, 3, LEN_RES - ft_strlen(vis->p2) - SP, vis->p2);
	wattroff(vis->res_tab, COLOR_PAIR(2));
	wrefresh(vis->res_tab);
}

void	init_wins(char *line, t_visual *vis)
{
	setlocale(LC_ALL, "");
	initscr();
	init_colors();
	curs_set(0);
	vis->term_size = LINES * COLS;
	read_sizes(line, vis);
	refresh();
	vis->res_tab = newwin(10, LEN_RES, 0, 5);
	vis->maps = newwin(vis->h + 2, (vis->w + 2) * 2, 0, LEN_RES + 10);
	result_board(vis);
	wattron(vis->maps, COLOR_PAIR(1));
	box(vis->maps, 0, 0);
	wattroff(vis->maps, COLOR_PAIR(1));
	box(vis->res_tab, 0, 0);
	wrefresh(vis->res_tab);
}
