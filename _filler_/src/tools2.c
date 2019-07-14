/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:19:14 by msaliuta         ###   ########.fr       */
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

int		algo3_2(int nbr_contact, t_token *p, t_map *map)
{
	if (nbr_contact == -1)
		return (0);
	p->final_x = p->tmp_x;
	p->final_n = p->tmp_n;
	print_result(p, map);
	return (1);
}

int		algo2(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->help.s_n;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = map->help.s_x;
		while (i2 > 0)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		algo2_2(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->help.s_n;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = -1;
		while (++i2 < map->help.s_x)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
		i--;
	}
	return (1);
}
