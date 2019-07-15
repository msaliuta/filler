/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:37:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		check_real_token_size(t_token *p)
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
			if (p->token[i][i2] == '*')
			{
				i2 < p->help.x ? p->help.x = i2 : 0;
				i2 > p->end_x ? p->end_x = i2 : 0;
				i < p->help.n ? p->help.n = i : 0;
				i > p->end_n ? p->end_n = i : 0;
			}
	}
}

void		check_token_size(char *line, t_token *p)
{
	int		i;
	int		temp;

	i = 0;
	p->help.s_x = 0;
	p->help.s_n = 0;
	while (line[i])
	{
		temp = 0;
		while (!(ft_isdigit(line[i]) == 0 && line[i]))
		{
			temp += line[i] - 48;
			ft_isdigit(line[i + 1]) == 1 ? temp *= 10 : 0;
			i++;
		}
		p->help.s_n == 0 ? p->help.s_n = temp : 0;
		(p->help.s_n != 0 | p->help.s_x == 0) ? p->help.s_x = temp : 0;
		i++;
	}
	ft_strdel(&line);
	parse_token(p);
}

void		parse_token(t_token *p)
{
	int		i;
	char	*str;

	i = 0;
	p->token == NULL ? 0 : free(p->token);
	p->token = (char **)malloc(sizeof(char *) * (p->help.s_n + 1));
	while (i < p->help.s_n)
	{
		get_next_line(0, &str);
		p->token[i] = (char *)malloc(sizeof(char *) * (p->help.s_x + 1));
		p->token[i] = ft_strcpy(p->token[i], (const char *)str);
		i++;
		ft_strdel(&str);
	}
	check_real_token_size(p);

}

void			check_maps(char *line, t_maps *maps)
{
	int			i;
	int			temp;

	i = 0;
	maps->help.s_x = 0;
	maps->help.s_n = 0;
	while (line[i])
	{
		temp = 0;
		while (!(ft_isdigit(line[i]) == 0 && line[i]))
		{
			temp += line[i] - 48;
			if (!(ft_isdigit(line[i + 1]) == 0))
				temp *= 10;
			i++;
		}
		if (maps->help.s_n == 0)
			maps->help.s_n = temp;
		else if (maps->help.s_x == 0)
			maps->help.s_x = temp;
		i++;
	}
	get_maps(maps);
}
