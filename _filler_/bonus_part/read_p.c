/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:51:04 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:10:00 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_p(t_visual *v)
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
	v->p1_name = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	v->p2_name = ft_strsub(line, ft_strrchr(line, '/') - line + 1,
		ft_strlen(line) - (ft_strrchr(line, '/') - line));
	ft_strdel(&line);
}
