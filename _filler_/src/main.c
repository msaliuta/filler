/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(void)
{
	t_token	*p;
	t_maps	*maps;

	maps = (t_maps *)malloc(sizeof(*maps));
	p = (t_token *)malloc(sizeof(*p));
	init_struct(maps, p);
	get_p(maps);
	while (1)
	{
		get_the_ret(maps, p);
		if (play(maps, p) == 1)
		{
			if (last_try(maps, p) == 1)
			{
				print_result(p, maps);
				exit(1);
			}
		}
	}
	free(p->token);
	free(maps);
	free(p);
	return (0);
}
