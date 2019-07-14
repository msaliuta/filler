# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 10:26:45 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/14 18:22:38 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			visualizer
INC =			-I ../libftprintf/includes -I ../includes/
LIB =			-lncurses -lft -L ../libftprintf
FLAGS =			-Wall -Wextra -Werror
LIST =			init_wins \
				main \
				over \
				print_line \
				read_p \
				read_s \
				show \
				size_check
OBJ =			$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(NAME)

obj/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): obj $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@rm -rf obj
	
fclean: clean
	@rm -f $(NAME)

re: fclean all
