/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:39:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/13 19:39:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

char			**alocate_matrix(size_t height, size_t width)
{
	char		**matrix;
	size_t		j;

	j = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * height + 1)))
		return (NULL);
	while (j < height)
	{
		if (!(matrix[j] = (char *)malloc(sizeof(char) * width + 1)))
			return (NULL);
		matrix[j++][width] = '\0';
	}
	matrix[height] = NULL;
	return (matrix);
}

char			**reading_create_map(char **matrix, char *line, t_matrix *size)
{
	size_t		x;
	size_t		y;
	size_t		i;

	x = 0;
	while (x < size->size_map_x && get_next_line(0, &line))
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			i--;
			while (line[i] && y < size->size_map_y)
				matrix[x][y++] = line[++i];
			x++;
		}
	}
	return (matrix);
}

static void		filler_creating_map_extension(t_matrix *matrix, char *line, \
	t_player *player)
{
	parse_map_size(line, matrix);
	matrix->map = reading_create_map(alocate_matrix(\
		matrix->size_map_x, matrix->size_map_y), line, matrix);
	matrix->field = set_cell_of_field(matrix, player);
	// print_field(matrix->field, matrix);
}

static void		filler_creating_piece_extension(t_matrix *matrix, char *line, \
	t_player *player)
{
	parse_piece_size(line, matrix);
	matrix->piece = parse_piece(line, alocate_matrix(\
		matrix->size_piece_height, matrix->size_piece_width), matrix);
	filler_algorithm(matrix, player);
	matrix_free(matrix);
}

int				main(void)
{
	t_player		*player;
	t_matrix		*matrix;
	char			*line;

	player = initial_player();
	matrix = initial_matrix();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isstrstr(line, "exec p1") || ft_isstrstr(line, "exec p2"))
			parse_players(line, player);
		if (ft_isstrstr(line, "Plateau"))
			filler_creating_map_extension(matrix, line, player);
		if (ft_isstrstr(line, "Piece"))
			filler_creating_piece_extension(matrix, line, player);
	}
	free(matrix);
	free(player);
	return (0);
}
