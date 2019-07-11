/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:31:49 by osamoile          #+#    #+#             */
/*   Updated: 2019/07/11 03:05:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece	read_piece(char *params)
{
	char	*line;
	char	**output;
	int		i;
	t_piece	piece;

	output = ft_strsplit(params, ' ');
	ft_strdel(&params);
	piece.x = ft_atoi(output[1]);
	piece.y = ft_atoi(output[2]);
	ft_arrclr(output);
	piece.array = ft_chartable(piece.x, piece.y);
	i = -1;
	while (++i < piece.x)
	{
		get_next_line(0, &line);
		ft_strcpy(piece.array[i], &line[0]);
		ft_strdel(&line);
	}
	reshape(&piece);
	return (piece);
}
