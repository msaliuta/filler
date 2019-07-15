/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:22 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_base(t_pf_env *o, char type)
{
	long			temp;
	unsigned long	val;

	val = 0;
	init_long_argm(o, &temp);
	if (type == 'O' || o->mod == Z || o->mod == T ||
		o->mod == J || o->mod == L || o->mod == LL)
		val = (unsigned long)temp;
	else if (o->mod == HH)
		val = (unsigned char)temp;
	else if (o->mod == H)
		val = (unsigned short)temp;
	else if (o->mod == NOMOD)
		val = (unsigned int)temp;
	if (type == 'b' || type == 'B')
		o->out = ft_ultoa_base(val, 2);
	if (type == 'o' || type == 'O')
		o->out = ft_ultoa_base(val, 8);
	if (type == 'x' || type == 'X')
		o->out = ft_ultoa_base(val, 16);
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(o->out);
	o->flmd.minus == 1 ? o->flmd.zero = 0 : 0;
	base_print(o, type, (long)val);
}

void	process_return(t_pf_env *o)
{
	int	*temp;

	if (o->tag.tag)
	{
		va_copy(o->ap[0], o->ap[1]);
		while (--o->tag.pos >= 0)
			temp = va_arg(o->ap[0], int *);
	}
	temp = va_arg(o->ap[0], int *);
	*temp = o->ret;
	++o->i;
}

void	process_ptraddr(t_pf_env *o, char type)
{
	long			temp;
	unsigned long	addr;

	init_long_argm(o, &temp);
	addr = (unsigned long)temp;
	if (o->flmd.prec == 0)
		o->out = ft_strdup("\0");
	else
		o->out = ft_ltoa_base(addr, 16);
	print_ptraddr(o, type);
}

void	process_nonprintable(t_pf_env *o)
{
	char	*temp;
	int		i;

	init_str_arg(o, &temp);
	i = -1;
	while (++i < o->flmd.width)
	{
		if (temp[i] >= 0 && temp[i] <= 10)
			print_first_dec(o, temp[i]);
		else if (temp[i] >= 11 && temp[i] <= 20)
			print_second_dec(o, temp[i]);
		else if (temp[i] >= 21 && temp[i] <= 31)
			print_pf_thirtd_dec(o, temp[i]);
		++o->ret;
	}
	++o->i;
}

void	process_percent(t_pf_env *o)
{
	if (o->flmd.minus)
	{
		o->ret += write(o->fd, "%", 1);
		while (o->flmd.width-- > 1)
			o->ret += write(o->fd, " ", 1);
	}
	else
	{
		while (o->flmd.width-- > 1)
		{
			if (o->flmd.zero)
				o->ret += write(o->fd, "0", 1);
			else
				o->ret += write(o->fd, " ", 1);
		}
		o->ret += write(o->fd, "%", 1);
	}
	++o->i;
}
