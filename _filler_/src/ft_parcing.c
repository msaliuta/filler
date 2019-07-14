/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:39 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:23:53 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			get_strat_pos(t_map *map)
{
	int			i2;
	static int	i3;

	if (i3 == map->help.s_n)
		return ;
	i3 = 0;
	while (++i3 < (map->help.s_n))
	{
		i2 = 0;
		while (++i2 < (map->help.s_x))
		{
			if ((map->map[i3][i2] == map->op[0] ||
				map->map[i3][i2] == map->op[1]))
			{
				map->pos_enemy_x = i2;
				map->pos_enemy_n = i3;
			}
			if ((map->map[i3][i2] == map->me[0] ||
				map->map[i3][i2] == map->me[1]))
			{
				map->help.x = i2;
				map->help.n = i3;
			}
		}
	}
}

void			get_map(t_map *map)
{
	int			i;
	char		*line;

	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	map->map = (char **)malloc(sizeof(char *) * (map->help.s_n + 1));
	while (++i <= (map->help.s_n - 1))
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
	get_strat_pos(map);
}

void			get_map_size(char *line, t_map *map)
{
	int			i;
	int			tmp;

	i = 0;
	map->help.s_x = 0;
	map->help.s_n = 0;
	while (line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (map->help.s_n == 0)
			map->help.s_n = tmp;
		else if (map->help.s_x == 0)
			map->help.s_x = tmp;
		i++;
	}
	get_map(map);
}

int				get_the_ret(t_map *map, t_token *p)
{
	char		*line;

	p->piece = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			get_map_size(line, map);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			get_piece_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
