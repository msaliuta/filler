/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_for_ptint(t_pf_env *o, int n)
{
	if (n == 1)
	{
		while (o->flmd.width-- > 1)
		{
			if (o->flmd.zero == 1)
				o->ret += write(o->fd, "0", 1);
			else
				o->ret += write(o->fd, " ", 1);
		}
	}
	else
	{
		while (o->flmd.width-- > 1)
		{
			if (o->flmd.zero == 1)
				o->ret += write(o->fd, "0", 1);
			else
				o->ret += write(o->fd, " ", 1);
		}
		++o->i;
	}
}

void	process_char(t_pf_env *o, char type)
{
	char	*stemp;
	int		ctemp;

	if (o->flmd.minus)
		o->flmd.zero = 0;
	if (type == 's')
	{
		init_str_arg(o, &stemp);
		if (stemp == NULL)
			return (str_for_print(o, 0));
		else if (o->flmd.prec)
			o->out = ft_strdup((char*)stemp);
		else
			o->out = ft_strdup("\0");
		str_print(o);
	}
	else if (type == 'c')
	{
		init_char_arg(o, &ctemp);
		char_print(o, ctemp);
	}
}

void	init_char_arg(t_pf_env *o, int *temp)
{
	if (o->tag.tag)
	{
		va_copy(o->ap[0], o->ap[1]);
		while (--o->tag.pos >= 0)
			*temp = va_arg(o->ap[0], int);
		return ;
	}
	*temp = va_arg(o->ap[0], int);
}

void	char_print(t_pf_env *o, char c)
{
	if (o->flmd.minus)
	{
		o->ret += write(o->fd, &c, 1);
		char_for_ptint(o, 1);
	}
	else
	{
		char_for_ptint(o, 1);
		o->ret += write(o->fd, &c, 1);
	}
	++o->i;
}
