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

# include "../libft/libft.h"

typedef struct	s_matrix
{
	char				**map;
	int					**field;
	char				**piece;
	size_t				size_piece_height;
	size_t				size_piece_width;
	size_t				size_map_x;
	size_t				size_map_y;
}				t_matrix;

typedef struct	s_get_coord
{
	size_t				x;
	size_t				y;
	int					n;
	struct s_get_coord	*next;
}				t_get_coord;

typedef struct	s_player
{
	unsigned int		first : 1;
	unsigned int		second : 1;
	char				symbol;
	size_t				enemy_last_x;
	size_t				enemy_last_y;
}				t_player;

/*
**	Structure initialize functions
*/

t_player		*initial_player(void);
t_matrix		*initial_matrix(void);
t_get_coord		*initial_get_coord_list(void);
int				**init_field(t_matrix *matrix, t_player *player);

/*
**	Printing data
*/

void			print_coordinats(size_t x, size_t y);
void			print_maxtrix(char **matrix);
void			print_field(int **matrix, t_matrix *size);
void			print_coord_list(t_get_coord *get_coord);

/*
**	Alocation memory function for map, field and piece
*/

char			**alocate_matrix(size_t height, size_t width);
int				**alocate_field(size_t height, size_t width);

/*
**	Parsing data
*/

void			parse_map_size(char *line, t_matrix *matrix);
void			parse_piece_size(char *line, t_matrix *matrix);
void			parse_players(char *line, t_player *player);
char			**parse_piece(char *line, char **piece, t_matrix *matrix);
void			parse_last_pace_of_enemy(char *line, t_player *player);

int				ft_isstrstr(char *big, char *little);
char			uppersymb(char symbol);

char			**reading_create_map(char **matrix, char *line, t_matrix *size);
void			coord_list_added(t_get_coord *list, size_t x, size_t y);
void			paste_digit(t_matrix *matrix, size_t *pace);
int				**set_cell_of_field(t_matrix *matrix, t_player *player);

void			matrix_free(t_matrix *matrix);
void			coordinats_free(t_get_coord **get_coord);
void			filler_algorithm(t_matrix *matrix, t_player *player);
int				ft_printf(const char *format, ...);

#endif
