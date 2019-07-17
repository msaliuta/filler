/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:24:42 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_placable(int i, int j, t_maps *maps, t_token *p)
{
	int x;
	int y;
	int count;

	x = -1;
	count = 0;
	if (i + p->help.s_n > maps->help.s_n || j + p->help.s_x > maps->help.s_x)
		return (1);
	while (++x <= (p->help.s_n - 1) && (y = -1))
		while (++y <= p->help.s_x - 1)
		{
			if (PT[x][y] == '*' && (MF[i + x][j + y] ==
				MO[0] || MF[i + x][j + y] == MO[0] - 32))
				return (1);
			if ((PT[x][y] == '*') & (MF[i + x][j + y] == MM[0]
				| MF[i + x][j + y] == MM[0] - 32))
				count++;
		}
	if (count == 1)
	{
		p->final_x = j;
		p->final_n = i;
		return (0);
	}
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
	while (++i < maps->help.s_n - 1 && (i2 = -1))
		while (++i2 < maps->help.s_x - 1)
			if ((ret = check_place(i, i2, maps, p)) == 0)
				return (0);
	return (1);
}
