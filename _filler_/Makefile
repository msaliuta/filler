# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 16:12:17 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/17 06:47:45 by msaliuta         ###   ########.fr        #
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
BOJD	=	bonus_part
INCS	=	-I$(addprefix $(LIBD)/, $(INCD)) -I $(INCD)

SRCS	=	main.c\
			get_functs.c\
			tools.c\
			tools2.c\
			ft_parcing.c\
			play.c\
			play2.c\
			check_functs.c

BOJS	=	$(addprefix $(BOJD)/, $(BNSS:.c=.o))
OBJS	=	$(addprefix $(OBJD)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBD)
	@$(MAKE) -C $(BOJD)
	@$(CMPL) $(CFLG) -o $(NAME) $^ -L$(LIBD) -lft $(INCS)
	@echo "msaliuta.filler is ready"

$(OBJD)/%.o: $(SRCD)/%.c
	@echo ".\c"
	@mkdir -p $(OBJD)
	@$(CMPL) $(CFLG) -o $@ -c $< $(INCS)

clean:
	@$(MAKE) -C $(BOJD) clean
	@$(MAKE) -C $(LIBD) clean
	@rm -rf $(OBJD)

fclean: clean
	@$(MAKE) -C $(BOJD) fclean
	@$(MAKE) -C $(LIBD) fclean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus
