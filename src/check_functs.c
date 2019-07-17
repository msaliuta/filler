/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:37:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:28:45 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		check_real_token_size(t_token *p)
{
	int		i;
	int		j;

	i = -1;
	p->help.x = p->help.s_x;
	p->help.n = p->help.s_n;
	while (++i < p->help.s_n)
	{
		j = -1;
		while (++j < p->help.s_x)
			if (PT[i][j] == '*')
			{
				j < p->help.x ? p->help.x = j : 0;
				j > p->end_x ? p->end_x = j : 0;
				i < p->help.n ? p->help.n = i : 0;
				i > p->end_n ? p->end_n = i : 0;
			}
	}
}

void		check_token_size(char *line, t_token *p)
{
	int		i;
	int		temp;

	i = 0;
	p->help.s_x = 0;
	p->help.s_n = 0;
	while (line[i])
	{
		temp = 0;
		while (!(ft_isdigit(line[i]) == 0 && line[i]))
		{
			temp += line[i] - 48;
			ft_isdigit(line[i + 1]) == 1 ? temp *= 10 : 0;
			i++;
		}
		p->help.s_n == 0 ? p->help.s_n = temp : 0;
		(p->help.s_n != 0 | p->help.s_x == 0) ? p->help.s_x = temp : 0;
		i++;
	}
	ft_strdel(&line);
	parse_token(p);
}

void		check_maps(char *line, t_maps *maps)
{
	int			i;
	int			temp;

	i = -1;
	maps->help.s_x = 0;
	maps->help.s_n = 0;
	while (line[++i])
	{
		temp = 0;
		while (!(ft_isdigit(line[i]) == 0 && line[i]))
		{
			temp += line[i] - 48;
			if (!(ft_isdigit(line[i + 1]) == 0))
				temp *= 10;
			i++;
		}
		if (maps->help.s_n == 0)
			maps->help.s_n = temp;
		else if (maps->help.s_x == 0)
			maps->help.s_x = temp;
	}
	get_maps(maps);
}

int			check_place(int i, int i2, t_maps *maps, t_token *p)
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
