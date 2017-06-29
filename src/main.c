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
	t_size *size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < size->map_x && get_next_line(0, &line))
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			i--;
			while (line[i] && y < size->map_y)
				matrix[x][y++] = line[++i];
			x++;
		}
	}
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

char			uppersymb(char symbol)
{
	if (symbol == 'x' || symbol == 'o')
		return (symbol - 32);
	else
		return (symbol);
}

int				check_enemy(t_matrix *matrix, int x, int y, char enemy, t_size *size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size->piece_height)
	{
		j = 0;
		while (j < size->piece_width)
		{
			if (((uppersymb(matrix->map[x + i][y + j]) == enemy) && matrix->piece[i][j] == '*'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				check_connect(t_matrix *matrix, int x, int y, t_player *player, t_size *size)
{
	int			overlap;
	int			i;
	int			j;
	char		enemy;

	overlap = 0;
	i = 0;
	enemy = player->symbol == 'O' ? 'X' : 'O';
	while (i < size->piece_height)
	{
		j = 0;
		while (j < size->piece_width)
		{
			if (((uppersymb(matrix->map[x + i][y + j]) == player->symbol) && matrix->piece[i][j] == '*') && \
				check_enemy(matrix, x, y, enemy, size))
				overlap++;
			j++;
		}
		i++;
	}
	return (overlap);
}

t_get_coord		*filler_algorithm(t_matrix *matrix, t_size *size, t_player *player)
{
	t_get_coord		*get_coord;
	int				x;
	int				y;

	get_coord = initial_get_coord_list();
	x = 0;
	while (x <= (size->map_x - size->piece_height))
	{
		y = 0;
		while (y <= (size->map_y - size->piece_width))
		{
			if (check_connect(matrix, x, y, player, size) == 1)
			{
				dprintf(2, "%jd %jd\n", get_coord->x, get_coord->y);
				coord_list_added(get_coord, x, y);
			}
			y++;
		}
		x++;
	}
	return (get_coord);
}

int				main(void)
{
	t_size			*size;
	t_player		*player;
	t_matrix		*matrix;
	t_get_coord		*get_coord;
	char			*line;

	size = initial_size();
	player = initial_player();
	matrix = initial_matrix();
	get_coord = initial_get_coord_list();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isstrstr(line, "exec p1") || ft_isstrstr(line, "exec p2"))
			parse_players(line, player);
		if (ft_isstrstr(line, "Plateau"))
		{
			parse_map_size(line, size);
			matrix->map = alocate_matrix(size->map_x, size->map_y);
			// dprintf(2, "map size:\nx : %zu\ny : %zu\n\n", map_size->x, map_size->y);
			matrix->map = reading_create_map(matrix->map, line, size);
		}
		if (ft_isstrstr(line, "Piece"))
		{
			parse_piece_size(line, size);
			// dprintf(2, "piece size:\nheight : %zu\nwidth : %zu\n\n", piece_size->height, piece_size->width);
			matrix->piece = alocate_matrix(size->piece_height, size->piece_width);
			matrix->piece = parse_piece(line, matrix->piece, size);
			player->symbol = player->first == 1 ? 'O' : 'X';
			// dprintf(2, "player : %c\n\n", player->symbol);
			get_coord = filler_algorithm(matrix, size, player);
			// print_coord_list(get_coord);
			// ft_putnbr(get_coord->x);
			// write(1, " ", 1);
			// ft_putnbr(get_coord->y);
			// write(1, "\n", 1);
		}
		// free(map_size);
		// free(piece_size);
		// free(player);
		// free(get_coord);
	}
	return (0);
}
