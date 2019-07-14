# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 16:12:17 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/14 18:12:13 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	resources/players/msaliuta.filler
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

SRCS	=	main.c\
			tools.c\
			tools2.c\
			ft_parcing.c\
			play.c\
			play2.c 

BOJS	=	$(addprefix $(BOJD)/, $(BNSS:.c=.o))
OBJS	=	$(addprefix $(OBJD)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBD)
	@$(CMPL) $(CFLG) -o $(NAME) $^ -L$(LIBD) -lft $(INCS)
	@echo "msaliuta.filler is ready"

$(OBJD)/%.o: $(SRCD)/%.c
	@echo ".\c"
	@mkdir -p $(OBJD)
	@$(CMPL) $(CFLG) -o $@ -c $< $(INCS)

clean:
	@$(MAKE) -C $(LIBD) clean
	@rm -rf $(OBJD)

fclean: clean
	@$(MAKE) -C $(LIBD) fclean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus

bonus: $(VISL)

$(VISL): $(BOJS)
	$(CMPL) -o $(VISL) $^ -L$(LIBD) -lft -lncurses
	
$(BOJD)/%.o: $(BNSD)/%.c
	mkdir -p $(BOJD)
	$(CMPL) $(CFLG) -c $< -o $@ -L$(LIBD) $(INCS)
