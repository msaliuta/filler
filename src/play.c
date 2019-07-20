/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:48 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:36:31 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		big_maps(t_maps *maps, t_token *p)
{
	int ret;

	p->touch = get_connect(maps);
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
		ret = bm_algo(maps, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

int		small_maps(t_maps *maps, t_token *p)
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
