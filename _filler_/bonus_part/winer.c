/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:01:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	winner(int p1, int p2, t_visual *vis)
{
	char	*text;
	char	*n;

	if (p1 > p2)
	{
		text = ft_strjoin(vis->p1, " WON!");
		n = ft_itoa(p1 - p2);
	}
	else
	{
		text = ft_strjoin(vis->p2, " WON!");
		n = ft_itoa(p2 - p1);
	}
	text = ft_strjoin(text, " by a margin of ");
	text = ft_strjoin(text, n);
	wattron(vis->res_tab, A_BOLD | COLOR_PAIR(5));
	mvwaddstr(vis->res_tab, 8, 35 - ft_strlen(text) / 2, text);
	wrefresh(vis->res_tab);
	freopen("/dev/tty", "r", stdin);
	getch();
	delwin(vis->maps);
	delwin(vis->res_tab);
	endwin();
}
