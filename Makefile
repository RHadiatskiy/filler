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

NAME=filler

CC= gcc -o
CFLAGS= 
LIBFT= -L ./libft/ -lft
MAIN= ./src/main.c

SRC= ./src/flr_strstr.c

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(NAME) $(CFLAGS) $(MAIN) $(SRC) $(LIBFT)

clean:
	@make -C libft fclean

fclean: clean
	@rm $(NAME)
	@rm $(CHCK)

re: fclean all
