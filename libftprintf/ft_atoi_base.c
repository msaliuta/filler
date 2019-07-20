/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:05:59 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/18 18:07:26 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi_base(const char *s, int base)
{
	long	n;
	int		np;

	n = 0;
	np = 1;
	while (*s == '\n' && *s == '\t' && *s == '\v' &&
			*s == ' ' && *s == '\f' && *s == '\r')
		++s;
	*s == '-' ? np = -1 : 0;
	*s == '-' || *s == '+' ? ++s : 0;
	while ((*s >= '0' && *s <= '9') ||
			(*s >= 'A' && *s <= 'F') ||
			(*s >= 'a' && *s <= 'f'))
	{
		n *= base;
		*s >= '0' && *s <= '9' ? n += *s - 48 : 0;
		*s >= 'A' && *s <= 'F' ? n += *s - 55 : 0;
		*s >= 'a' && *s <= 'f' ? n += *s - 87 : 0;
		++s;
	}
	return ((int)n * np);
}