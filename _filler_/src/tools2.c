/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 05:56:17 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		left_top(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

	i = maps->help.s_n + 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (--i > 0 && (i2 = maps->help.s_x + 1))
		while (--i2 > 0)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
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
	while (--i > 0 && (i2 = -1))
		while (++i2 < maps->help.s_x)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}
