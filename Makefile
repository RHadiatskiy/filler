# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 18:51:19 by rhadiats          #+#    #+#              #
#    Updated: 2017/05/22 18:51:22 by rhadiats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Colors -----
BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"
# ==================

NAME=filler

CC= gcc -o
CFLAGS= 
LIBFT= -L ./libft/ -lft
MAIN= ./src/main.c

SRC= ./src/ft_isstrstr.c ./src/filler_initial.c \
	./src/filler_parsing.c ./src/filler_lists.c \
	./src/filler_create_field.c

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(NAME) $(CFLAGS) $(MAIN) $(SRC) $(LIBFT)
	@echo $(GREEN)"\tFILLER IS COMPILED"$(RESET)

clean:
	@make -C libft fclean
	@echo $(RED)"\tFILLER IS CLEANED"$(RESET)

fclean: clean
	@rm $(NAME)

re: fclean all
