/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:51:04 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 19:21:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_p(t_visual *vis)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	get_next_line(0, &line);
	vis->p1 = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	vis->p2 = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
}
