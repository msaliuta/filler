/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:48 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:23:53 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	go_contact1(t_map *map, t_token *p)
{
	int i;
	int i2;
	int ret;

	i = map->help.s_n - 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = map->help.s_x - 1;
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

int	go_contact2(t_map *map, t_token *p)
{
	int i;
	int i2;
	int ret;

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

int	big_map(t_map *map, t_token *p)
{
	int ret;

	get_contact(p, map);
	if (p->contact == 0)
	{
		if (map->help.n < map->pos_enemy_n)
		{
			if (go_contact1(map, p) == 1)
				return (1);
		}
		else if (map->help.n >= map->pos_enemy_n)
		{
			if (go_contact2(map, p) == 1)
				return (1);
		}
	}
	else
	{
		ret = algo3(map, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

int	small_map(t_map *map, t_token *p)
{
	if (map->help.n < (map->help.s_n / 2))
	{
		if (map->help.x < (map->help.s_x / 2))
		{
			if (algo2(map, p) == 1)
				return (1);
		}
		else if (map->help.x >= (map->help.s_x / 2))
			if (algo2_2(map, p) == 1)
				return (1);
	}
	else
	{
		if (map->help.x < (map->help.s_x / 2))
		{
			if (algo1(map, p) == 1)
				return (1);
		}
		else if (map->help.x >= (map->help.s_x / 2))
			if (algo1_2(map, p) == 1)
				return (1);
	}
	return (0);
}

int	play(t_map *map, t_token *p)
{
	if (map->help.s_n < 20)
		return (small_map(map, p));
	if (map->help.s_n >= 20)
		return (big_map(map, p));
	return (0);
}
