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
VISUALIZE=./visualize/visualize

CC= gcc -o
CFLAGS= -Wall -Wextra -Werror
LIBFT= -L ./libft/ -lft
LIBPRINTF= ./src/ft_printf/libftprintf.a
MAIN= ./src/main.c
MAIN_VISUALIZE = ./visualize/src/main.c

SRC= ./src/filler_brain.c ./src/filler_free.c \
	./src/filler_initial.c ./src/filler_setting_field.c \
	./src/filler_parsing.c ./src/filler_lists.c \
	./src/filler_create_field.c ./src/filler_printing.c \
	./src/filler_addition_func.c

SRC_VISUALIZE = ./visualize/src/visualize_addition_func.c \
				./visualize/src/visualize_initial.c \
				./visualize/src/visualize_parsing.c

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C ./src/ft_printf
	@$(CC) $(NAME) $(CFLAGS) $(MAIN) $(SRC) $(LIBFT) $(LIBPRINTF)
	@$(CC) $(VISUALIZE) $(CFLAGS) $(MAIN_VISUALIZE) $(SRC_VISUALIZE) $(LIBFT) $(LIBPRINTF)
	@echo $(GREEN)"\tFILLER IS COMPILED"

clean:
	@make -C libft fclean
	@make -C ./src/ft_printf fclean
	@echo $(RED)"\tFILLER IS CLEANED"

fclean: clean
	@rm $(NAME)
	@rm $(VISUALIZE)

re: fclean all
