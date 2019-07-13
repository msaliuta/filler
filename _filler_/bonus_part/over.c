/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:59:24 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:10:05 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	over(t_visual *v)
{
	freopen("/dev/tty", "r", stdin);
	getch();
	delwin(v->map);
	delwin(v->scale);
	endwin();
}
