/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:25:57 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int		is_placable(int i, int i2, t_map *map, t_token *p)
{
	int j;
	int j2;
	int count;

	j = -1;
	count = 0;
	if (i + p->help.s_n > map->help.s_n || i2 + p->help.s_x > map->help.s_x)
		return (1);
	while (++j <= (p->help.s_n - 1))
	{
		j2 = -1;
		while (++j2 <= (p->help.s_x - 1))
		{
			if (p->piece[j][j2] == '*' && (map->map[i + j][i2 + j2] ==
				map->op[0] || map->map[i + j][i2 + j2] == map->op[0] - 32))
				return (1);
			((p->piece[j][j2] == '*') & (map->map[i + j][i2 + j2] == map->me[0]
				| map->map[i + j][i2 + j2] == map->me[0] - 32)) ? count++ : 0;
		}
	}
	if (is_placable2(p, count, i, i2) == 0)
		return (0);
	return (1);
}

void	print_result(t_token *p, t_map *map)
{
	ft_putnbr(p->final_n);
	ft_putchar(' ');
	ft_putnbr(p->final_x);
	ft_putchar('\n');
	map->help.x = p->final_x;
	map->help.n = p->final_n;
}

int		last_try(t_map *map, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < map->help.s_n - 1)
	{
		i2 = -1;
		while (++i2 < map->help.s_x - 1)
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

void	init_struct(t_map *map, t_token *p)
{
	map->map = NULL;
	map->help.s_x = 0;
	map->help.s_n = 0;
	p->final_x = 0;
	p->final_n = 0;
	p->help.s_x = 0;
	p->help.s_n = 0;
	map->pos_enemy_x = 0;
	map->pos_enemy_n = 0;
	map->help.x = 0;
	map->help.n = 0;
	p->help.x = 0;
	p->end_x = 0;
	p->help.n = 0;
	p->end_n = 0;
	p->contact = 0;
}
