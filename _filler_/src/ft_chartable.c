/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:57:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/11 19:58:09 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_chartable(int x, int y)
{
	char	**table;
	int		i;

	table = (char**)ft_memalloc((x + 1) * sizeof(char*));
	table[x] = 0;
	i = -1;
	while (++i < x)
		table[i] = ft_strnew(y);
	return (table);
}
