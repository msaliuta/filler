/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 03:16:18 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 03:16:31 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		choose_player(t_game *game)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		game->me = 'o';
		game->opponent = 'x';
	}
	else
	{
		game->me = 'x';
		game->opponent = 'o';
	}
	ft_strdel(&line);
}
