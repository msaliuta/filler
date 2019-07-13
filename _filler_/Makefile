# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 16:12:17 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/13 17:18:21 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	msaliuta.filler
CMPL	=	cc
CFLG	=	$(addprefix -W, all extra error)
LIBD	=	libftprintf
BNSD	=	bonus_part
SRCD	=	src
INCD	=	includes
OBJD	=	objs
BOJD	=	boun
INCS	=	-I$(addprefix $(LIBD)/, $(INCD)) -I $(INCD)
VISL	=	visualizer
BNSS	=	init_wins.c\
			main.c\
			over.c\
			print_line.c\
			read_p.c\
			read_s.c\
			show.c\
			size_check.c

SRCS	=	analyze_map.c\
			create_map.c\
			distance_sum.c\
			distance_to_cell.c\
			distance_to_opponent.c\
			ft_chartable.c\
			get_p.c\
			left.c\
			main.c\
			put_piece.c\
			read_map.c\
			read_piece.c\
			reshape.c\
			start_end_x.c\
			start_end_y.c\
			top.c\
			way_closed.c


BOJS	=	$(addprefix $(BOJD)/, $(BNSS:.c=.o))
OBJS	=	$(addprefix $(OBJD)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBD)
	$(CMPL) $(CFLG) -o $(NAME) $^ -L$(LIBD) -lft $(INCS)

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	$(CMPL) $(CFLG) -o $@ -c $< $(INCS)

clean:
	@$(MAKE) -C $(LIBD) clean
	@rm -rf $(OBJD)

fclean: clean
	$(MAKE) -C $(LIBD) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus

bonus: $(VISL)

$(VISL): $(BOJS)
	$(CMPL) -o $(VISL) $^ -L$(LIBD) -lft -lncurses
	
$(BOJD)/%.o: $(BNSD)/%.c
	mkdir -p $(BOJD)
	$(CMPL) $(CFLG) -c $< -o $@ -L$(LIBD) $(INCS)
