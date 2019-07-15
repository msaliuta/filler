/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_res_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:26:03 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 19:27:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	show_res_tab(WINDOW *res_tab, int p1, int p2)
{
	char	*n;

	n = ft_itoa(p1);
	mvwaddstr(res_tab, 5, 15, n);
	ft_strdel(&n);
	n = ft_itoa(p2);
	mvwaddstr(res_tab, 5, LEN_RES - 15, n);
	ft_strdel(&n);
	mvwaddstr(res_tab, 5, 10, CAT);
	mvwaddstr(res_tab, 5, LEN_RES - 10, MONKEY);
	wrefresh(res_tab);
}
