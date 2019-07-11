# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 15:53:40 by osamoile          #+#    #+#              #
#    Updated: 2019/07/12 00:40:16 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			msaliuta.filler
INC =			-I ./includes \
				-I ./libftprintf/includes
LIB =			-lft -L ./libftprintf
FLAGS =			-Wall -Wextra -Werror
LIST =			main \
				read_piece \
				create_map \
				distance_sum \
				analyze_map \
				put_piece\
				read_map\
				start_end_x\
				start_end_y\
				reshape\
				choose_player\
				distance_to_cell\
				distance_to_opponent\
				top\
				left\
				way_closed\
				ft_chartable\

OBJ =			$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): obj $(OBJ)
	@make -C libftprintf
	@gcc $(OBJ) -o $(NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@make -C libftprintf clean
	@rm -rf obj
	
fclean: clean
	@make -C libftprintf fclean
	@rm -f $(NAME)

re: fclean all
