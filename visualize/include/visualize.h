/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:19:42 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/06 13:19:45 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZE_H
# define VISUALIZE_H

/*
**	Set colors for dprintf
*/

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define GREEN		"\033[1;32m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../../libft/libft.h"

typedef struct	s_matrix
{
	char				**map;
	size_t				size_map_x;
	size_t				size_map_y;
}				t_matrix;

typedef struct	s_player
{
	unsigned int		first : 1;
	unsigned int		second : 1;
	size_t				res_filler;
	size_t				res_enemy;
	int					flag : 1;
}				t_player;

int				ft_isstrstr(char *big, char *little);
char			uppersymb(char symbol);

t_matrix		*initial_matrix(void);
t_player		*initial_player(void);
void			parse_map_size(char *line, t_matrix *matrix);
void			parse_players(char *line, t_player *player);
void			parse_result(char *line, t_player *player);
char			**alocate_matrix(size_t height, size_t width);
char			**reading_create_map(char **matrix, char *line, t_matrix *size);
void			print_map(char **map, t_player *player);
void			map_free(t_matrix *matrix);
int				ft_printf(const char *format, ...);

#endif
