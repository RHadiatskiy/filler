# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/22 18:51:19 by rhadiats          #+#    #+#              #
#    Updated: 2017/04/22 18:51:22 by rhadiats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/ft_atoi.c src/ft_x_high.c \
		src/ft_d_low.c src/ft_flags_reset.c \
		src/ft_i.c src/ft_isdigit.c \
		src/ft_itoa_base.c src/len_u_prec.c \
		src/ft_o_low.c src/ft_output_func.c \
		src/ft_percent.c src/ft_printing.c \
		src/ft_s_low.c src/ft_strdup.c \
		src/ft_strjoin.c src/ft_strlen.c \
		src/ft_strlenchr.c src/ft_u_low.c \
		src/ft_c_low.c src/ft_x_low.c \
		src/parsing.c src/ft_strcmp.c \
		src/ft_p.c src/ft_o_high.c \
		src/ft_u_high.c src/ft_c_high.c \
		src/ft_none.c src/ft_d_high.c \
		src/u_mask.c src/ft_s_high.c \
		src/ft_fl_low.c src/ft_fl_high.c \
		src/ft_strlen_u.c ft_printf.c

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
HEAD = include/ft_printf.h

all: $(NAME)
$(NAME): $(OBJ)

	@ar -cru $(NAME) $(OBJ)
	@ranlib $(NAME)
%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
