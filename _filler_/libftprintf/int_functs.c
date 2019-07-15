/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:11 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_long_argm(t_pf_env *o, long *temp)
{
	if (o->tag.tag)
	{
		va_copy(o->ap[0], o->ap[1]);
		while (--o->tag.pos >= 0)
			*temp = va_arg(o->ap[0], long);
		return ;
	}
	*temp = va_arg(o->ap[0], long);
}

void	process_int(t_pf_env *o)
{
	long temp;
	long i;

	init_long_argm(o, &temp);
	i = (long long)temp;
	if (o->flmd.minus == 1)
		o->flmd.zero = 0;
	if (o->flmd.prec >= 0)
		o->flmd.zero = 0;
	if (temp == LLONG_MIN || temp == LONG_MIN)
		o->out = ft_strdup("-9223372036854775808");
	else if (o->mod == Z)
		o->out = ft_itoa((size_t)i);
	else if (o->mod == HH)
		o->out = ft_itoa((char)i);
	else if (o->mod == H)
		o->out = ft_itoa((short)i);
	else if (o->mod == NOMOD)
		o->out = ft_itoa((int)i);
	else if (o->mod == L || o->mod == T ||
			o->mod == LL || o->mod == J)
		o->out = ft_ltoa((long)i);
	else if (o->mod == L1)
		o->out = ft_itoa((unsigned long)i);
	digit_print(o);
}

void	init_double_argm(t_pf_env *o, double *temp)
{
	if (o->tag.tag)
	{
		va_copy(o->ap[0], o->ap[1]);
		while (--o->tag.pos >= 0)
			*temp = va_arg(o->ap[0], double);
		return ;
	}
	*temp = va_arg(o->ap[0], double);
}

void	process_unsint(t_pf_env *o, char type)
{
	long temp;

	o->flmd.space = 0;
	o->flmd.plus = 0;
	init_long_argm(o, &temp);
	if (temp == LLONG_MIN || temp == LONG_MIN)
		o->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U' || o->mod == L ||
			o->mod == T || o->mod == J || o->mod == LL
			|| o->mod == L1)
		o->out = ft_ultoa((unsigned long)temp);
	else if (o->mod == Z)
		o->out = ft_ltoa((long)temp);
	else if (o->mod == H)
		o->out = ft_ltoa((unsigned short)temp);
	else if (o->mod == HH)
		o->out = ft_ultoa((unsigned char)temp);
	else if (o->mod == NOMOD && type != 'U')
		o->out = ft_ultoa((unsigned int)temp);
	digit_print(o);
}
