/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:24:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/17 07:37:22 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define WORK 42
# define MM maps->me
# define MO maps->op
# define PT p->token
# define MF maps->field

typedef struct		s_help
{
	int				x;
	int				n;
	int				s_x;
	int				s_n;
	int				oppx;
	int				oppn;
}					t_help;

typedef struct		s_token
{
	t_help			help;
	int				final_x;
	int				final_n;
	int				end_x;
	int				end_n;
	int				touch;
	int				temp_x;
	int				temp_n;
	int				nbr_touch;
	char			**token;
}					t_token;

typedef struct		s_maps
{
	t_help			help;
	char			**field;
	char			*op;
	char			*me;
}					t_maps;

int					play(t_maps *maps, t_token *p);
void				finish(t_token *p, t_maps *maps);

/*
**get_functs.c.c
*/

int					read_data(t_maps *maps, t_token *p);
void				start_place(t_maps *maps);
void				get_maps(t_maps *maps);
void				parse_token(t_token *p);
int					get_connect(t_maps *maps);

/*
**check.c
*/

void				check_real_token_size(t_token *p);
void				check_token_size(char *line, t_token *p);
void				check_maps(char *line, t_maps *maps);
int					check_place(int i, int i2, t_maps *maps, t_token *p);

/*
**play.c
*/

int					big_maps(t_maps *maps, t_token *p);
int					small_maps(t_maps *maps, t_token *p);

/*
**touch.c
*/

int					count_touch(t_maps *maps, t_token *p, int y, int x);
int					go_touch1(t_maps *maps, t_token *p);
int					go_touch2(t_maps *maps, t_token *p);

/*
**help.c
*/

int					is_placable(int i, int i2, t_maps *maps, t_token *p);
void				print_result(t_token *p, t_maps *maps);
int					last_try(t_maps *maps, t_token *p);

/*
**direct.c
*/

int					left_top(t_maps *maps, t_token *p);
int					right_top(t_maps *maps, t_token *p);
int					left_down(t_maps *maps, t_token *p);
int					right_down(t_maps *maps, t_token *p);
int					bm_algo(t_maps *maps, t_token *p);

#endif
