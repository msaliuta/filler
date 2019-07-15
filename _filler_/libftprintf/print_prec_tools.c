/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:19 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(long double d)
{
	char	*s;
	long	temp;
	int		len;
	int		neg;

	neg = (d < 0 ? -1 : 1);
	len = (d < 0 ? 1 : 0);
	d *= neg;
	temp = (long)d;
	while (temp > 0 && len++ >= 0)
		temp /= 10;
	while (d - (long)d != 0 && len++ >= 0)
		d *= 10;
	s = ft_strnew(len);
	while (--len >= 0)
	{
		s[len] = (long)d % 10 + '0';
		d /= 10;
		if (neg == -1 && len == 1)
		{
			s[0] = '-';
			break ;
		}
	}
	return (s);
}

void	nan_inf(t_pf_env *o, char type, double var)
{
	if (var != var)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			o->ret += write(o->fd, "nan", 3);
		else
			o->ret += write(o->fd, "NAN", 3);
	}
	else if (var * 2 == var && var != 0)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			o->ret += write(o->fd, "inf", 3);
		else
			o->ret += write(o->fd, "INF", 3);
	}
	++o->i;
}

void	delete_zero(char *temp)
{
	int		i;

	i = ft_strlen(temp);
	while (--i >= 0 && temp[i] == '0')
		temp[i] = '\0';
}

void	hex_prec(t_pf_env *o, double d, char **frac, char type)
{
	unsigned long	cmp;
	long			num;
	int				len;
	int				cnt;
	int				i;

	len = (o->flmd.prec < 0 ? 13 : o->flmd.prec);
	*frac = ft_strnew(len);
	cmp = 0x0008000000000000;
	i = -1;
	num = *(long*)&d;
	while (++i < len)
	{
		cnt = 0;
		cnt += (num & cmp) == 0 ? 0 : 8;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 4;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 2;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 1;
		cmp >>= 1;
		frac[0][i] = (cnt < 10 ? cnt + 48 : cnt + type - 10);
	}
}
