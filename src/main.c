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
	t_map_size *map_size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < map_size->x && get_next_line(0, &line))
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			i--;
			while (line[i] && y < map_size->y)
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

int				check_connect(t_matrix *matrix, int x, int y, t_player *player, t_piece_size *piece_size)
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
			if ((uppersymb(matrix->map[x + i][y + j]) == player->symbol) && matrix->piece[i][j] == '*')
				overlap++;
			j++;
		}
		i++;
	}
	return (overlap);
}

t_get_coord		*filler_algorithm(t_matrix *matrix, t_map_size *map_size, t_piece_size *piece_size, t_player *player)
{
	t_get_coord		*get_coord;
	int				x;
	int				y;

	get_coord = initial_get_coord_list();
	x = 0;
	while (x <= (map_size->x - piece_size->height))
	{
		y = 0;
		while (y <= (map_size->y - piece_size->width))
		{
			if (check_connect(matrix, x, y, player, piece_size) == 1)
				coord_list_added(get_coord, x, y);
			y++;
		}
		x++;
	}
	return (get_coord);
}

int				main(void)
{
	t_map_size		*map_size;
	t_piece_size	*piece_size;
	t_player		*player;
	t_matrix		*matrix;
	t_get_coord		*get_coord;
	char			*line;

	map_size = initial_map_size();
	piece_size = initial_piece_size();
	player = initial_player();
	matrix = initial_matrix();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isstrstr(line, "exec p1") || ft_isstrstr(line, "exec p2"))
			parse_players(line, player);
		if (ft_isstrstr(line, "Plateau"))
		{
			parse_map_size(line, map_size);
			matrix->map = alocate_matrix(map_size->x, map_size->y);
			// dprintf(2, "map size:\nx : %zu\ny : %zu\n\n", map_size->x, map_size->y);
			matrix->map = reading_create_map(matrix->map, line, map_size);
		}
		if (ft_isstrstr(line, "Piece"))
		{
			parse_piece_size(line, piece_size);
			// dprintf(2, "piece size:\nheight : %zu\nwidth : %zu\n\n", piece_size->height, piece_size->width);
			matrix->piece = alocate_matrix(piece_size->height, piece_size->width);
			matrix->piece = parse_piece(line, matrix->piece, piece_size);
			player->symbol = player->first == 1 ? 'O' : 'X';
			// dprintf(2, "player : %c\n\n", player->symbol);
			get_coord = filler_algorithm(matrix, map_size, piece_size, player);
			// print_coord_list(get_coord);
			ft_putnbr(get_coord->x);
			write(1, " ", 1);
			ft_putnbr(get_coord->y);
			write(1, "\n", 1);
		}
		// free(map_size);
		// free(piece_size);
		// free(player);
		// free(get_coord);
	}
	return (0);
}
