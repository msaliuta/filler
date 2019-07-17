/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:48 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 06:45:56 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	go_touch1(t_maps *maps, t_token *p)
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

int	go_touch2(t_maps *maps, t_token *p)
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

int	check_place(int i, int i2, t_maps *maps, t_token *p)
{
	int ret;

	ret = is_placable(i, i2, maps, p);
	if (ret == 0)
	{
		print_result(p, maps);
		return (0);
	}
	return (1);
}

int	big_maps(t_maps *maps, t_token *p)
{
	int ret;

	p->touch = get_touch(maps);
	if (p->touch == 0)
	{
		if (maps->help.n < maps->help.oppn)
		{
			if (go_touch1(maps, p) == 1)
				return (1);
		}
		else if (maps->help.n >= maps->help.oppn)
			if (go_touch2(maps, p) == 1)
				return (1);
	}
	else if (p->touch != 0)
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
