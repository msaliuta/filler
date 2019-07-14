/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:24:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/14 20:27:41 by msaliuta         ###   ########.fr       */
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
	int				contact;
	int				tmp_x;
	int				tmp_n;
	int				nbr_contact;
	char			**piece;
	int				real_size_x;
	int				real_size_n;
}					t_token;

typedef struct		s_map
{
	t_help			help;
	char			**map;
	char			*op;
	int				pos_enemy_x;
	int				pos_enemy_n;
	char			*me;
}					t_map;


/*
**main.c
*/

void				get_real_piece_size(t_token *p);
void				get_piece(t_token *p);
void				get_piece_size(char *line, t_token *p);
void				get_p(t_map *map);

/*
**ft_parcing.c
*/

void				get_strat_pos(t_map *map);
void				get_map(t_map *map);
void				get_map_size(char *line, t_map *map);
int					get_the_ret(t_map *map, t_token *p);

/*
**play.c
*/

int					go_contact1(t_map *map, t_token *p);
int					go_contact2(t_map *map, t_token *p);
int					big_map(t_map *map, t_token *p);
int					small_map(t_map *map, t_token *p);
int					play(t_map *map, t_token *p);

/*
**play2.c
*/

void				get_contact(t_token *p, t_map *map);
int					count_contact(t_map *map, t_token *p, int y, int x);
int					algo3(t_map *map, t_token *p);
int					algo1(t_map *map, t_token *p);
int					algo1_2(t_map *map, t_token *p);

/*
**tools.c
*/

int					is_number(char c);
int					is_placable(int i, int i2, t_map *map, t_token *p);
void				print_result(t_token *p, t_map *map);
int					last_try(t_map *map, t_token *p);
void				init_struct(t_map *map, t_token *p);

/*
**tools2.c
*/

int					is_placable2(t_token *p, int count, int i, int i2);
int					algo3_2(int nbr_contact, t_token *p, t_map *map);
int					algo2(t_map *map, t_token *p);
int					algo2_2(t_map *map, t_token *p);

#endif
