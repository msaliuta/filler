/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:58 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:39:47 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_touch(t_maps *maps, t_token *p, int y, int x)
{
	int	i;
	int	j;
	int o;

	i = -1;
	p->nbr_touch = 0;
	while (++i < p->help.s_n && (j = -1))
		while (++j < p->help.s_x)
			if (PT[i][j] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((j + x + o) < maps->help.s_x && (j + x - o) > 0 &&
						(i + y + o) < maps->help.s_n && (i + y - o) > 0)
						(MF[i + y][j + x + o] == MO[0] ||
						MF[i + y][j + x - o] == MO[0] ||
						MF[i + y + o][j + x] == MO[0] ||
						MF[i + y - o][j + x] == MO[0]) ?
						p->nbr_touch += (4 - o) : 0;
			}
	return (p->nbr_touch);
}

int		go_touch1(t_maps *maps, t_token *p)
{
	int i;
	int i2;
	int ret;

	i = maps->help.s_n;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (--i > 0 && (i2 = maps->help.s_x))
		while (--i2 > 0)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}

int		go_touch2(t_maps *maps, t_token *p)
{
	int i;
	int i2;
	int ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n - 1 && (i2 = -1))
		while (++i2 < maps->help.s_x - 1)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}
