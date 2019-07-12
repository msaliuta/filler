/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:16:18 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/12 03:30:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_p(t_game *game)
{
	char *line;

	get_next_line(0, &line);
	game->me = (ft_strstr(line, "p1") ? 'o' : 'x');
	game->opponent = (game->me == 'o' ? 'x' : '0');
	ft_strdel(&line);
}
