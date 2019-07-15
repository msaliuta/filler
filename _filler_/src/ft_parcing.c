/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:39 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			get_strat_pos(t_maps *maps)
{
	int			i2;
	static int	i3;

	if (i3 == maps->help.s_n)
		return ;
	i3 = 0;
	while (++i3 < (maps->help.s_n))
	{
		i2 = 0;
		while (++i2 < (maps->help.s_x))
		{
			if ((maps->field[i3][i2] == maps->op[0] ||
				maps->field[i3][i2] == maps->op[1]))
			{
				maps->opp_x = i2;
				maps->opp_n = i3;
			}
			if ((maps->field[i3][i2] == maps->me[0] ||
				maps->field[i3][i2] == maps->me[1]))
			{
				maps->help.x = i2;
				maps->help.n = i3;
			}
		}
	}
}

void			get_maps(t_maps *maps)
{
	int			i;
	char		*line;

	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	maps->field = (char **)malloc(sizeof(char *) * (maps->help.s_n + 1));
	while (++i <= (maps->help.s_n - 1))
	{
		get_next_line(0, &line);
		maps->field[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
	get_strat_pos(maps);
}

