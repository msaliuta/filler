/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:12:06 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:37:22 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			read_data(t_maps *maps, t_token *p)
{
	char		*line;

	PT = NULL;
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

void		start_place(t_maps *maps)
{
	int			i;
	static int	j;

	if (j == maps->help.s_n)
		return ;
	j = 0;
	while (++j < (maps->help.s_n))
	{
		i = 0;
		while (++i < (maps->help.s_x))
		{
			if ((maps->field[j][i] == MO[0] ||
				maps->field[j][i] == MO[1]))
			{
				maps->help.oppx = i;
				maps->help.oppn = j;
			}
			if ((maps->field[j][i] == MM[0] ||
				maps->field[j][i] == MM[1]))
			{
				maps->help.x = i;
				maps->help.n = j;
			}
		}
	}
}

void		get_maps(t_maps *maps)
{
	int			i;
	char		*line;

	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	maps->field = (char **)malloc(sizeof(char *) * (maps->help.s_n + 1));
	while (++i <= (maps->help.s_n - 1))
	{
		get_next_line(0, &line);
		maps->field[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
	start_place(maps);
}

void		parse_token(t_token *p)
{
	int		i;
	char	*str;

	i = 0;
	PT == NULL ? 0 : free(PT);
	PT = (char **)malloc(sizeof(char *) * (p->help.s_n + 1));
	while (i < p->help.s_n)
	{
		get_next_line(0, &str);
		PT[i] = (char *)malloc(sizeof(char *) * (p->help.s_x + 1));
		PT[i] = ft_strcpy(PT[i], (const char *)str);
		i++;
		ft_strdel(&str);
	}
	check_real_token_size(p);
}

int			get_connect(t_maps *maps)
{
	int	i;
	int	j;

	i = 2;
	while (++i < maps->help.s_n - 3)
	{
		j = 2;
		while (++j < maps->help.s_x - 3)
			if (MF[i][j] == MM[0] || MF[i][j] == MM[1])
				if (MF[i][j + 3] == MO[0] || MF[i][j - 3] == MO[0]
					|| MF[i + 3][j] == MO[0] || MF[i - 3][j] == MO[0]
					|| MF[i][j + 3] == MO[1] || MF[i][j - 3] == MO[1]
					|| MF[i + 3][j] == MO[1] || MF[i - 3][j] == MO[1])
					return (1);
	}
	return (0);
}
