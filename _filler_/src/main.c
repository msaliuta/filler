/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:25:57 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_real_piece_size(t_token *p)
{
	int		i;
	int		i2;

	i = -1;
	p->help.x = p->help.s_x;
	p->help.n = p->help.s_n;
	while (++i < p->help.s_n)
	{
		i2 = -1;
		while (++i2 < p->help.s_x)
			if (p->piece[i][i2] == '*')
			{
				i2 < p->help.x ? p->help.x = i2 : 0;
				i2 > p->end_x ? p->end_x = i2 : 0;
				i < p->help.n ? p->help.n = i : 0;
				i > p->end_n ? p->end_n = i : 0;
			}
	}
	p->real_size_x = (p->end_x - p->help.x) + 1;
	p->real_size_n = (p->end_n - p->help.n) + 1;
}

void		get_piece(t_token *p)
{
	int		i;
	char	*line;

	i = 0;
	p->piece == NULL ? 0 : free(p->piece);
	p->piece = (char **)malloc(sizeof(char *) * (p->help.s_n + 1));
	while (i < p->help.s_n)
	{
		get_next_line(0, &line);
		p->piece[i] = (char *)malloc(sizeof(char *) * (p->help.s_x + 1));
		p->piece[i] = ft_strcpy(p->piece[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
	get_real_piece_size(p);
}

void		get_piece_size(char *line, t_token *p)
{
	int		i;
	int		tmp;

	i = 0;
	p->help.s_x = 0;
	p->help.s_n = 0;
	while (line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			is_number(line[i + 1]) == 0 ? tmp *= 10 : 0;
			i++;
		}
		p->help.s_n == 0 ? p->help.s_n = tmp : 0;
		(p->help.s_n != 0 | p->help.s_x == 0) ? p->help.s_x = tmp : 0;
		i++;
	}
	ft_strdel(&line);
	get_piece(p);
}

void			get_p(t_map *map)
{
	char		*line;

	get_next_line(0, &line);
	map->me = (ft_strstr(line, "p1") ? "Oo" : "Xx");
	map->op = (ft_strstr(map->me, "Oo") ? "Xx" : "Oo");
}

int			main(void)
{
	t_map	*map;
	t_token	*p;

	map = (t_map *)malloc(sizeof(*map));
	p = (t_token *)malloc(sizeof(*p));
	init_struct(map, p);
	get_p(map);
	while (1)
	{
		get_the_ret(map, p);
		if (play(map, p) == 1)
		{
			if (last_try(map, p) == 1)
			{
				print_result(p, map);
				exit(1);
			}
		}
	}
	free(p->piece);
	free(map);
	free(p);
	return (0);
}
