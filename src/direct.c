/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:28:25 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		left_top(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	ret;

	i = maps->help.s_n + 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (--i > 0 && (j = maps->help.s_x + 1))
		while (--j > 0)
			if ((ret = check_place(i, j, maps, p)) == 0)
				return (0);
	return (1);
}

int		right_top(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	ret;

	i = maps->help.s_n + 1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (--i > 0 && (j = -1))
		while (++j < maps->help.s_x)
			if ((ret = check_place(i, j, maps, p)) == 0)
				return (0);
	return (1);
}

int		left_down(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n && (j = maps->help.s_x))
		while (--j > 0)
			if ((ret = check_place(i, j, maps, p)) == 0)
				return (0);
	return (1);
}

int		right_down(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_n = 0;
	ret = 0;
	while (++i < maps->help.s_n && (j = -1))
		while (++j < maps->help.s_x)
			if ((ret = check_place(i, j, maps, p)) == 0)
				return (0);
	return (1);
}

int		bm_algo(t_maps *maps, t_token *p)
{
	int	i;
	int	j;
	int	n_t_tmp;
	int	nbr_touch;

	nbr_touch = -1;
	i = maps->help.s_n - (p->help.s_n - p->end_n);
	p->temp_x = 0;
	p->temp_n = 0;
	while (--i >= 0 && (j = maps->help.s_x - (p->help.s_x - p->end_x)))
		while (--j >= 0)
			if (is_placable(i, j, maps, p) == 0 &&
				(n_t_tmp = count_touch(maps, p, i, j)))
				if (n_t_tmp > nbr_touch)
				{
					nbr_touch = n_t_tmp;
					p->temp_x = j;
					p->temp_n = i;
				}
	if (nbr_touch == -1)
		return (0);
	p->final_x = p->temp_x;
	p->final_n = p->temp_n;
	print_result(p, maps);
	return (1);
}
