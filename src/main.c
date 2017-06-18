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
	int			j;

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

char			**reading_create_map(char **matrix, char *line, \
	t_map_size *map_size, t_piece_size *piece_size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (get_next_line(0, &line) && !ft_isstrstr(line, "Piece") && \
		x < map_size->x)
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			i--;
			while (line[i] != '\n' && y < map_size->y)
				matrix[x][y++] = line[++i];
			x++;
		}
	}
	parse_piece_size(line, piece_size);
	return (matrix);
}

void			print_maxtrix(char **matrix)
{
	int			i;
	int			j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			write(1, &matrix[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int				check_connect(t_matrix *matrix, int x, int y, char you, t_piece_size *piece_size)
{
	int			overlap;
	int			i;
	int			j;

	overlap = 0;
	i = 0;
	while (i < piece_size->height)
	{
		j = 0;	
		while (j < piece_size->width)
		{
			if (matrix->map[x + i][y + j] == you && matrix->piece[i][j] == '*')
				overlap++;
			j++;
		}
		i++;
	}
	return (overlap);
}

void			filler_algorithm(t_matrix *matrix, t_map_size *map_size, t_piece_size *piece_size, char you)
{
	char		enemy;
	int			x;
	int			y;

	x = 0;
	enemy = (you == 'o' || you == 'O') ? 'X' : 'O';
	while (x <= (map_size->x - piece_size->height))
	{
		y = 0;
		while (y <= (map_size->y - piece_size->width))
		{
			if (check_connect(matrix, x, y, you, piece_size) == 1)
			{
				ft_putnbr_fd(x, 1);
				write(1, " ", 1);
				ft_putnbr_fd(y, 1);
				write(1, "\n", 1);
				break ;
			}
			y++;
		}
		x++;
	}
}

int				main(void)
{
	t_map_size		*map_size;
	t_piece_size	*piece_size;
	t_player		*player;
	t_matrix		*matrix;

	map_size = initial_map_size();
	piece_size = initial_piece_size();
	player = initial_player();
	matrix = initial_matrix();
	// filler_initial(matrix, matrix_size, piece_size, player);
	matrix = filler_parsing(matrix, map_size, piece_size, player);
	print_maxtrix(matrix->map);
	print_maxtrix(matrix->piece);
	filler_algorithm(matrix, map_size, piece_size, 'O');
	free(map_size);
	free(piece_size);
	return (0);
}
