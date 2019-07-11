/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 02:58:52 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 02:59:10 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_game *game)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	ft_strdel(&line);
	i = -1;
	while (++i < game->map.x)
	{
		get_next_line(0, &line);
		ft_strcpy(&game->map.array[i][0], &line[4]);
		ft_strdel(&line);
	}
}
