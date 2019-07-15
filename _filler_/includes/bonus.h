/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:07:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:28:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <curses.h>
# include <locale.h>
# include "libft.h"

# define DELAY 10000
# define LEN_RES 70
# define SP 5
# define CAT "\xF0\x9F\x99\x80"
# define MONKEY "\xF0\x9F\x99\x88"

typedef struct	s_visual
{
	WINDOW		*maps;
	int			h;
	int			w;
	int			term_size;
	WINDOW		*res_tab;
	char		*p1;
	char		*p2;
	int			score1;
	int			score2;
}				t_visual;

void			show_maps(t_visual *vis);
void			show_res_tab(WINDOW *res_tab, int p1, int p2);
void			winner(int p1, int p2, t_visual *vis);
void			show(t_visual *vis);
void	        print_line(char *line, int i, t_visual *vis);
void	        read_p(t_visual *vis);
void	        read_sizes(char *line, t_visual *vis);

/*
**tab_res.c
*/

void 			init_colors(void);
void			result_board(t_visual *vis);
void	        init_wins(char *line, t_visual *vis);

#endif
