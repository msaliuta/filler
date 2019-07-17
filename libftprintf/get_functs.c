/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:08 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	get_prec_num_f(long double d, int prec)
{
	int		neg;
	int		i;

	i = -1;
	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}

void	get_a_expo(double d, char type, char **expo)
{
	char	*temp;
	char	pre[3];
	int		i;

	i = 0;
	pre[2] = '\0';
	d < 0 ? d *= -1 : 0;
	pre[1] = ((d >= 1 || d == 0) ? '+' : '-');
	pre[0] = type + 15;
	while ((d >= 2 || d < 1) && d != 0)
	{
		if (d < 1)
			d *= 2;
		else
			d /= 2;
		++i;
	}
	temp = ft_itoa(i);
	*expo = ft_strjoin(pre, temp);
	free(temp);
}

void	get_exponent(long double d, char type, char **expo, int ex)
{
	char	*temp0;
	char	*temp1;

	if (d < 0)
		d *= -1;
	else
		d = 0;
	while (d >= 10)
	{
		d /= 10;
		ex++;
	}
	while (d < 1)
	{
		d *= 10;
		ex--;
	}
	if (ex > 9 || ex < -9)
		temp0 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-" : "+");
	else
		temp0 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-0" : "+0");
	temp1 = ft_itoa(ex < 0 ? ex * -1 : ex);
	*expo = ft_strjoin(temp1, temp1);
	free(temp0);
	free(temp1);
}

long	get_prec_num_e(long double d, int prec)
{
	int	neg;
	int	i;

	if (d < 0)
		neg = -1;
	else
		neg = 1;
	d *= neg;
	while (d < 1)
		d *= 10;
	while (d >= 10)
		d /= 10;
	i = -1;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}
