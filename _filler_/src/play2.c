/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:58 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:19:14 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_contact(t_token *p, t_map *map)
{
	int	i;
	int	i2;

	i = 2;
	while (++i < map->help.s_n - 3)
	{
		i2 = 2;
		while (++i2 < map->help.s_x - 3)
		{
			if (map->map[i][i2] == map->me[0] || map->map[i][i2] == map->me[1])
				if (map->map[i][i2 + 3] == map->op[0] || map->map[i][i2 - 3]
					== map->op[0]
					|| map->map[i + 3][i2] == map->op[0] || map->map[i - 3][i2]
					== map->op[0]
					|| map->map[i][i2 + 3] == map->op[1] || map->map[i][i2 - 3]
					== map->op[1]
					|| map->map[i + 3][i2] == map->op[1] || map->map[i - 3][i2]
					== map->op[1])
				{
					p->contact = 1;
					return ;
				}
		}
	}
}

int		count_contact(t_map *map, t_token *p, int y, int x)
{
	int	i;
	int	i2;
	int o;

	i = -1;
	p->nbr_contact = 0;
	while (++i < p->help.s_n)
	{
		i2 = -1;
		while (++i2 < p->help.s_x)
			if (p->piece[i][i2] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((i2 + x + o) < map->help.s_x && (i2 + x - o) > 0 &&
						(i + y + o) < map->help.s_n && (i + y - o) > 0)
						(map->map[i + y][i2 + x + o] == map->op[0] ||
						map->map[i + y][i2 + x - o] == map->op[0] ||
						map->map[i + y + o][i2 + x] == map->op[0] ||
						map->map[i + y - o][i2 + x] == map->op[0]) ?
						p->nbr_contact += (4 - o) : 0;
			}
	}
	return (p->nbr_contact);
}

int		algo3(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	nbr_contact_tmp;
	int	nbr_contact;

	nbr_contact = -1;
	i = map->help.s_n - (p->help.s_n - p->end_n);
	p->tmp_x = 0;
	p->tmp_n = 0;
	while (--i >= 0)
	{
		i2 = map->help.s_x - (p->help.s_x - p->end_x);
		while (--i2 >= 0)
			if (is_placable(i, i2, map, p) == 0)
			{
				nbr_contact_tmp = count_contact(map, p, i, i2);
				if (nbr_contact_tmp > nbr_contact)
				{
					nbr_contact = nbr_contact_tmp;
					p->tmp_x = i2;
					p->tmp_n = i;
				}
			}
	}
	return (algo3_2(nbr_contact, p, map));
}

int		algo1(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < map->help.s_n)
	{
		i2 = map->help.s_x;
		while (--i2 > 0)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}

int		algo1_2(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < map->help.s_n)
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
	}
	return (1);
}
