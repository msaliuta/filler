/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 06:46:06 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(void)
{
	t_token	*p;
	t_maps	*maps;
	char	*str;

	maps = (t_maps *)malloc(sizeof(*maps));
	p = (t_token *)malloc(sizeof(*p));
	ft_bzero(p, sizeof(t_token));
	ft_bzero(maps, sizeof(t_maps));
	get_next_line(0, &str);
	MM = (ft_strstr(str, "p1") ? "Oo" : "Xx");
	MO = (ft_strstr(MM, "Oo") ? "Xx" : "Oo");
	while (WORK && (get_the_ret(maps, p)))
		if (play(maps, p))
			last_try(maps, p) ? finish(p, maps) : 0;
	return (0);
}

int			play(t_maps *maps, t_token *p)
{
	if (maps->help.s_n < 20)
		return (small_maps(maps, p));
	if (maps->help.s_n >= 20)
		return (big_maps(maps, p));
	return (0);
}

void		finish(t_token *p, t_maps *maps)
{
	print_result(p, maps);
	exit(1);
	free(PT);
	free(maps);
	free(p);
}
