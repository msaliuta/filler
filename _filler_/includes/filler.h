/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:24:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 20:34:33 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct 		s_help
{
	int				x;
	int 			n;
	int				s_x;
	int				s_n;
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
	int				opp_x;
	int				opp_n;
	char			*me;
}					t_maps;

void				check_token_size(char *line, t_token *p);
void				check_real_token_size(t_token *p);
void				parse_token(t_token *p);

/*
**get_functs.c.c
*/

void				get_p(t_maps *maps);
void				check_maps(char *line, t_maps *maps);
int					get_the_ret(t_maps *maps, t_token *p);


/*
**ft_parcing.c
*/

void				get_strat_pos(t_maps *maps);
void				get_maps(t_maps *maps);

/*
**play.c
*/

int					go_touch1(t_maps *maps, t_token *p);
int					go_touch2(t_maps *maps, t_token *p);
int					big_maps(t_maps *maps, t_token *p);
int					small_maps(t_maps *maps, t_token *p);
int					play(t_maps *maps, t_token *p);

/*
**play2.c
*/

void				get_touch(t_token *p, t_maps *maps);
int					count_touch(t_maps *maps, t_token *p, int y, int x);
int					algo3(t_maps *maps, t_token *p);
int					left_down(t_maps *maps, t_token *p);
int					right_down(t_maps *maps, t_token *p);

/*
**tools.c
*/

int					is_placable(int i, int i2, t_maps *maps, t_token *p);
void				print_result(t_token *p, t_maps *maps);
int					last_try(t_maps *maps, t_token *p);
void				init_struct(t_maps *maps, t_token *p);

/*
**tools2.c
*/

int					is_placable2(t_token *p, int count, int i, int i2);
int					algo3_2(int nbr_touch, t_token *p, t_maps *maps);
int					left_top(t_maps *maps, t_token *p);
int					right_top(t_maps *maps, t_token *p);

#endif
