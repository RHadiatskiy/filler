/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:36:51 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/13 19:36:53 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct	s_piece_size
{
	size_t			height;
	size_t			width;
}				t_piece_size;

typedef struct	s_matrix_size
{
	size_t			x;
	size_t			y;
}				t_matrix_size;

typedef struct	s_player
{
	unsigned int	first : 1;
	unsigned int	second : 1;
}				t_player;

typedef struct	s_matrix
{
	char			**map;
	char			**piece;
}				t_matrix;

int				ft_isstrstr(char *big, char *little);
t_matrix_size	*initial_matrix_size(void);
t_piece_size	*initial_piece_size(void);
t_player		*initial_player(void);
t_matrix		*initial_matrix(void);
char			**alocate_matrix(size_t height, size_t width);
char			**reading_create_map(char **matrix, char *line, \
	t_matrix_size *matrix_size, t_piece_size *piece_size);
void			parse_matrix_size(char *line, t_matrix_size *matrix_size);
void			parse_piece_size(char *line, t_piece_size *piece_size);
void			parse_players(char *line, t_player *player);
char			**parse_piece(char *line, char **piece, \
	t_piece_size *piece_size);
void			filler_initial(t_matrix *matrix, t_matrix_size *matrix_size, \
	t_piece_size *piece_size, t_player *player);
t_matrix		*filler_parsing(t_matrix *matrix, t_matrix_size *matrix_size, \
	t_piece_size *piece_size, t_player *player);

#endif
