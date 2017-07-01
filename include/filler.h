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

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define GREEN		"\033[1;32m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct	s_size
{
	size_t			piece_height;
	size_t			piece_width;
	size_t			map_x;
	size_t			map_y;
}				t_size;

typedef struct	s_player
{
	unsigned int		first : 1;
	unsigned int		second : 1;
	char				symbol;
}				t_player;

typedef struct	s_matrix
{
	char				**map;
	int					**field;
	char				**piece;
}				t_matrix;

typedef struct	s_get_coord
{
	size_t				x;
	size_t				y;
	int					n;
	struct s_get_coord	*next;
}				t_get_coord;

int				ft_isstrstr(char *big, char *little);
t_size			*initial_size(void);
t_player		*initial_player(void);
t_matrix		*initial_matrix(void);
char			**alocate_matrix(size_t height, size_t width);
char			**reading_create_map(char **matrix, char *line, t_size *size);
void			parse_map_size(char *line, t_size *size);
void			parse_piece_size(char *line, t_size *size);
void			parse_players(char *line, t_player *player);
char			**parse_piece(char *line, char **piece, t_size *size);
void			filler_initial(t_matrix *matrix, t_size *map_size, \
	t_player *player);
t_matrix		*filler_parsing(t_matrix *matrix, t_size *size, \
	t_player *player);
t_get_coord		*initial_get_coord_list(void);
void			coord_list_added(t_get_coord *list, size_t x, size_t y);
void			print_coord_list(t_get_coord *get_coord);
void			matrix_free(t_matrix *matrix, t_size *size);
char			uppersymb(char symbol);

int				**alocate_field(size_t height, size_t width);
int				**init_field(t_matrix *matrix, t_size *size, t_player *player);
int				**fill_field(t_matrix *matrix, t_size *size, t_player *player);
void			print_field(int **matrix, t_size *size);

#endif
