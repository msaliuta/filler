/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:24:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:32:41 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_map
{
	char	**array;
	int		x;
	int		y;
	int		**int_array;
}				t_map;

typedef struct	s_piece
{
	char	**array;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
}				t_piece;

typedef struct	s_game
{
	t_piece	piece;
	t_map	map;
	char	me;
	char	opponent;

}				t_game;

int				main(void);
void			get_p(t_game *game);
void			create_map(char *plateau, t_game *game);
void			read_map(t_game *game);
t_piece			read_piece(char *params);
int				distance_to_cell(t_map map, char me, int x, int y);
void			distance_to_opponent(t_map map, char opponent);
void			analyze_map(t_game *game);
void			put_piece(t_game *game, int *put_x, int *put_y);
void			start_end_x(t_piece *piece, int *end_x);
void			start_end_y(t_piece *piece, int *end_y);
void			reshape(t_piece *piece);
int				distance_sum(t_game *game, int *sum, int i, int j);
int				top(t_map map, char player);
int				left(t_map map, char player);
int				way_closed(t_game *game, int me_top);
char			**ft_chartable(int x, int y);

#endif
