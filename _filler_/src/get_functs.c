/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:12:06 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			get_p(t_maps *maps)
{
	char		*str;

	get_next_line(0, &str);
	maps->me = (ft_strstr(str, "p1") ? "Oo" : "Xx");
	maps->op = (ft_strstr(maps->me, "Oo") ? "Xx" : "Oo");
}

int				get_the_ret(t_maps *maps, t_token *p)
{
	char		*line;

	p->token = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			check_maps(line, maps);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			check_token_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
