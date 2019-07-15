/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:37:32 by msaliuta          #+#    #+#             */
/*   Updated: 2018/10/30 18:37:34 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmaps(char const *s, char (*f)(char))
{
	int		i;
	char	*mapspedstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mapspedstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapspedstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		mapspedstr[i] = f(s[i]);
	}
	mapspedstr[i] = '\0';
	return (mapspedstr);
}
