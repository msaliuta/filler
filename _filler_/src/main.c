/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:31:49 by osamoile          #+#    #+#             */
/*   Updated: 2019/07/11 03:17:13 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	char	*line;
	int		put_x;
	int		put_y;
	t_game	game;

	game.piece.array = NULL;
	choose_player(&game);
	while (1)
	{
		get_next_line(0, &line);
		if (!ft_strstr(line, "Plateau"))
			return (0);
		if (game.map.array == NULL)
			create_map(line, &game);
		ft_strdel(&line);
		read_map(&game);
		get_next_line(0, &line);
		ft_arrclr(game.piece.array);
		game.piece = read_piece(line);
		analyze_map(&game);
		put_piece(&game, &put_x, &put_y);
		ft_printf("%i %i\n",
			put_x - game.piece.start_x, put_y - game.piece.start_y);
	}
	return (0);
}
