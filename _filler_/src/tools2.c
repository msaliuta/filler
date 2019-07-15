/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_placable2(t_token *p, int count, int i, int i2)
{
	if (count == 1)
	{
		p->final_x = i2;
		p->final_n = i;
		return (0);
	}
	return (1);
}

int		algo3_2(int nbr_touch, t_token *p, t_maps *maps)
{
	if (nbr_touch == -1)
		return (0);
	p->final_x = p->temp_x;
	p->final_n = p->temp_n;
	print_result(p, maps);
	return (1);
}

int		left_top(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = maps->help.s_n;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = maps->help.s_x;
		while (i2 > 0)
		{
			ret = is_placable(i, i2, maps, p);
			if (ret == 0)
			{
				print_result(p, maps);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		right_top(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = maps->help.s_n + 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (--i > 0)
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
