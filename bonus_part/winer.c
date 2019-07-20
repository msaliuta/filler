/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:01:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/16 17:41:43 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_p(t_visual *vis)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	get_next_line(0, &line);
	vis->p1 = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	vis->p2 = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
}

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
	delwin(VM);
	delwin(vis->res_tab);
	endwin();
}

void	print_line(char *line, int i, t_visual *vis)
{
	int	j;

	j = 3;
	while (++j < vis->w + 4)
	{
		if (line[j] == 'O' || line[j] == 'o')
		{
			mvwaddstr(VM, i + 1, 2 * j - 6, CAT);
			vis->score1++;
		}
		else if (line[j] == 'X' || line[j] == 'x')
		{
			mvwaddstr(VM, i + 1, 2 * j - 6, MONKEY);
			vis->score2++;
		}
		else
			mvwaddstr(VM, i + 1, 2 * j - 6, ". ");
		wattron(VM, COLOR_PAIR(3));
	}
}

void	read_sizes(char *line, t_visual *vis)
{
	char	**nums;

	nums = ft_strsplit(line, ' ');
	vis->h = ft_atoi(nums[1]);
	vis->w = ft_atoi(nums[2]);
	ft_arrclr(nums);
}
