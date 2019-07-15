/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:48 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	go_touch1(t_maps *maps, t_token *p)
{
	int i;
	int i2;
	int ret;

	i = maps->help.s_n - 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = maps->help.s_x - 1;
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

int	go_touch2(t_maps *maps, t_token *p)
{
	int i;
	int i2;
	int ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n - 1)
	{
		i2 = -1;
		while (++i2 < maps->help.s_x - 1)
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

int	big_maps(t_maps *maps, t_token *p)
{
	int ret;

	get_touch(p, maps);
	if (p->touch == 0)
	{
		if (maps->help.n < maps->opp_n)
		{
			if (go_touch1(maps, p) == 1)
				return (1);
		}
		else if (maps->help.n >= maps->opp_n)
		{
			if (go_touch2(maps, p) == 1)
				return (1);
		}
	}
	else
	{
		ret = algo3(maps, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

int	small_maps(t_maps *maps, t_token *p)
{
	if (maps->help.n < (maps->help.s_n / 2))
	{
		if (maps->help.x < (maps->help.s_x / 2))
		{
			if (left_top(maps, p) == 1)
				return (1);
		}
		else if (maps->help.x >= (maps->help.s_x / 2))
			if (right_top(maps, p) == 1)
				return (1);
	}
	else if (maps->help.n >= (maps->help.s_n / 2))
	{
		if (maps->help.x < (maps->help.s_x / 2))
		{
			if (left_down(maps, p) == 1)
				return (1);
		}
		else if (maps->help.x >= (maps->help.s_x / 2))
			if (right_down(maps, p) == 1)
				return (1);
	}
	return (0);
}

int	play(t_maps *maps, t_token *p)
{
	if (maps->help.s_n < 20)
		return (small_maps(maps, p));
	if (maps->help.s_n >= 20)
		return (big_maps(maps, p));
	return (0);
}
