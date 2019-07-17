/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:58 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 06:46:35 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_touch(t_maps *maps)
{
	int	i;
	int	i2;

	i = 2;
	while (++i < maps->help.s_n - 3)
	{
		i2 = 2;
		while (++i2 < maps->help.s_x - 3)
			if (MF[i][i2] == MM[0] || MF[i][i2] == MM[1])
				if (MF[i][i2 + 3] == MO[0] || MF[i][i2 - 3] == MO[0]
					|| MF[i + 3][i2] == MO[0] || MF[i - 3][i2] == MO[0]
					|| MF[i][i2 + 3] == MO[1] || MF[i][i2 - 3] == MO[1]
					|| MF[i + 3][i2] == MO[1] || MF[i - 3][i2] == MO[1])
					return (1);
	}
	return (0);
}

int		count_touch(t_maps *maps, t_token *p, int y, int x)
{
	int	i;
	int	i2;
	int o;

	i = -1;
	p->nbr_touch = 0;
	while (++i < p->help.s_n && (i2 = -1))
		while (++i2 < p->help.s_x)
			if (PT[i][i2] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((i2 + x + o) < maps->help.s_x && (i2 + x - o) > 0 &&
						(i + y + o) < maps->help.s_n && (i + y - o) > 0)
						(MF[i + y][i2 + x + o] == MO[0] ||
						MF[i + y][i2 + x - o] == MO[0] ||
						MF[i + y + o][i2 + x] == MO[0] ||
						MF[i + y - o][i2 + x] == MO[0]) ?
						p->nbr_touch += (4 - o) : 0;
			}
	return (p->nbr_touch);
}

int		algo3(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	n_t_tmp;
	int	nbr_touch;

	nbr_touch = -1;
	i = maps->help.s_n - (p->help.s_n - p->end_n);
	p->temp_x = 0;
	p->temp_n = 0;
	while (--i >= 0 && (j = maps->help.s_x - (p->help.s_x - p->end_x)))
		while (--j >= 0)
			if (is_placable(i, j, maps, p) == 0 &&
				(n_t_tmp = count_touch(maps, p, i, j)))
				if (n_t_tmp > nbr_touch)
				{
					nbr_touch = n_t_tmp;
					p->temp_x = j;
					p->temp_n = i;
				}
	if (nbr_touch == -1)
		return (0);
	p->final_x = p->temp_x;
	p->final_n = p->temp_n;
	print_result(p, maps);
	return (1);
}

int		left_down(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n && (i2 = maps->help.s_x))
		while (--i2 > 0)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}

int		right_down(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n && (i2 = -1))
		while (++i2 < maps->help.s_x)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}
