/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:58 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_touch(t_token *p, t_maps *maps)
{
	int	i;
	int	i2;

	i = 2;
	while (++i < maps->help.s_n - 3)
	{
		i2 = 2;
		while (++i2 < maps->help.s_x - 3)
		{
			if (maps->field[i][i2] == maps->me[0] || maps->field[i][i2] == maps->me[1])
				if (maps->field[i][i2 + 3] == maps->op[0] || maps->field[i][i2 - 3]
					== maps->op[0]
					|| maps->field[i + 3][i2] == maps->op[0] || maps->field[i - 3][i2]
					== maps->op[0]
					|| maps->field[i][i2 + 3] == maps->op[1] || maps->field[i][i2 - 3]
					== maps->op[1]
					|| maps->field[i + 3][i2] == maps->op[1] || maps->field[i - 3][i2]
					== maps->op[1])
				{
					p->touch = 1;
					return ;
				}
		}
	}
}

int		count_touch(t_maps *maps, t_token *p, int y, int x)
{
	int	i;
	int	i2;
	int o;

	i = -1;
	p->nbr_touch = 0;
	while (++i < p->help.s_n)
	{
		i2 = -1;
		while (++i2 < p->help.s_x)
			if (p->token[i][i2] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((i2 + x + o) < maps->help.s_x && (i2 + x - o) > 0 &&
						(i + y + o) < maps->help.s_n && (i + y - o) > 0)
						(maps->field[i + y][i2 + x + o] == maps->op[0] ||
						maps->field[i + y][i2 + x - o] == maps->op[0] ||
						maps->field[i + y + o][i2 + x] == maps->op[0] ||
						maps->field[i + y - o][i2 + x] == maps->op[0]) ?
						p->nbr_touch += (4 - o) : 0;
			}
	}
	return (p->nbr_touch);
}

int		algo3(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	nbr_touch_temp;
	int	nbr_touch;

	nbr_touch = -1;
	i = maps->help.s_n - (p->help.s_n - p->end_n);
	p->temp_x = 0;
	p->temp_n = 0;
	while (--i >= 0)
	{
		i2 = maps->help.s_x - (p->help.s_x - p->end_x);
		while (--i2 >= 0)
			if (is_placable(i, i2, maps, p) == 0)
			{
				nbr_touch_temp = count_touch(maps, p, i, i2);
				if (nbr_touch_temp > nbr_touch)
				{
					nbr_touch = nbr_touch_temp;
					p->temp_x = i2;
					p->temp_n = i;
				}
			}
	}
	return (algo3_2(nbr_touch, p, maps));
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
	while (++i < maps->help.s_n)
	{
		i2 = maps->help.s_x;
		while (--i2 > 0)
		{
			ret = is_placable(i, i2, maps, p);
			if (ret == 0)
			{
				print_result(p, maps);
				return (0);
			}
		}
	}
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
	while (++i < maps->help.s_n)
	{
		i2 = -1;
		while (++i2 < maps->help.s_x)
		{
			ret = is_placable(i, i2, maps, p);
			if (ret == 0)
			{
				print_result(p, maps);
				return (0);
			}
		}
	}
	return (1);
}
