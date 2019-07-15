/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:34:33 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_placable(int i, int i2, t_maps *maps, t_token *p)
{
	int j;
	int j2;
	int count;

	j = -1;
	count = 0;
	if (i + p->help.s_n > maps->help.s_n || i2 + p->help.s_x > maps->help.s_x)
		return (1);
	while (++j <= (p->help.s_n - 1))
	{
		j2 = -1;
		while (++j2 <= (p->help.s_x - 1))
		{
			if (p->token[j][j2] == '*' && (maps->field[i + j][i2 + j2] ==
				maps->op[0] || maps->field[i + j][i2 + j2] == maps->op[0] - 32))
				return (1);
			if ((p->token[j][j2] == '*') & (maps->field[i + j][i2 + j2] == maps->me[0]
				| maps->field[i + j][i2 + j2] == maps->me[0] - 32))
				count++;
		}
	}
	if (is_placable2(p, count, i, i2) == 0)
		return (0);
	return (1);
}

void	print_result(t_token *p, t_maps *maps)
{
	ft_putnbr(p->final_n);
	ft_putchar(' ');
	ft_putnbr(p->final_x);
	ft_putchar('\n');
	maps->help.x = p->final_x;
	maps->help.n = p->final_n;
}

int		last_try(t_maps *maps, t_token *p)
{
	int	i;
	int	i2;
	int	ret;

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

void	init_struct(t_maps *maps, t_token *p)
{
	maps->field = NULL;
	maps->help.s_x = 0;
	maps->help.s_n = 0;
	p->final_x = 0;
	p->final_n = 0;
	p->help.s_x = 0;
	p->help.s_n = 0;
	maps->opp_x = 0;
	maps->opp_n = 0;
	maps->help.x = 0;
	maps->help.n = 0;
	p->help.x = 0;
	p->end_x = 0;
	p->help.n = 0;
	p->end_n = 0;
	p->touch = 0;
}
