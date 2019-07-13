/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:57:45 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:10:07 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	size_check(t_visual *v, char *line)
{
	delwin(v->map);
	delwin(v->scale);
	endwin();
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	freopen("/dev/tty", "r", stdin);
	ft_printf("%s%s\n%s",
		COLOR_PINK,
		"Error: please don't resize terminal during visualizer processing.",
		COLOR_RESET);
	exit(0);
}
