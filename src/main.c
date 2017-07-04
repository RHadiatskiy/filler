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

int				check_zeros(t_matrix *matrix, t_size *size);


void			matrix_free(t_matrix *matrix, t_size *size)
{
	size_t		x;

	x = size->map_x - 1;
	if (matrix->map && matrix->field)
	{
		while (size->map_x && x)
		{
			free(matrix->map[size->map_x--]);
			free(matrix->field[x--]);
		}
		free(matrix->map);
		free(matrix->field);
	}
	if (matrix->piece)
	{
		while (size->piece_height)
			free(matrix->piece[size->piece_height--]);
		free(matrix->piece);
	}
}

void			print_coordinats(size_t x, size_t y)
{
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
}

int				check_sum(t_matrix *matrix, size_t x, size_t y, t_size *size)
{
	int			i;
	int			j;
	int			sum;

	i = 0;
	sum = 0;
	while (i < size->piece_height)
	{
		j = 0;
		while (j < size->piece_width)
		{
			if (matrix->piece[i][j] == '*')
				sum += matrix->field[x + i][y + j]; 
			j++;
		}
		i++;
	}
	dprintf(2, "\n\n%sSUM : %d%s\n\n", YELLOW, sum, RESET);
	return (sum);
}

void			choose_coord(t_matrix *matrix, t_get_coord *get_coord, t_size *size)
{
	t_get_coord	*tmp;
	int			sum;
	size_t		x;
	size_t		y;
	
	x = get_coord->x;
	y = get_coord->y;
	sum = check_sum(matrix, x, y, size);
	dprintf(2, "\n\n%sSUMMA : %d%s\n\n", RED, sum, RESET);	
	tmp = get_coord;
	while (tmp->next)
	{
		if (sum > (check_sum(matrix, tmp->next->x, tmp->next->y, size)))
		{
			x = tmp->next->x;
			y = tmp->next->y;
		}
		tmp = tmp->next;
	}
	dprintf(2, "\n\n%sX : %jd%s\n", YELLOW, x, RESET);
	dprintf(2, "%sY : %jd%s\n\n", YELLOW, y, RESET);
	print_coordinats(x, y);
}

char			uppersymb(char symbol)
{
	if (symbol == 'x' || symbol == 'o')
		return (symbol - 32);
	else
		return (symbol);
}

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
	dprintf(2, "\n");
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
				dprintf(2, "%s%c%s", RED, matrix[i][j++], RESET);
			else
				dprintf(2, "%c", matrix[i][j++]);
		}
		dprintf(2, "\n");
		i++;
	}
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
	size_t		i;
	size_t		j;
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
	size_t			x;
	size_t			y;

	get_coord = initial_get_coord_list();
	x = 0;
	while (x <= (size->map_x - size->piece_height))
	{
		y = 0;
		while (y <= (size->map_y - size->piece_width))
		{
			if (check_connect(matrix, x, y, player, size) == 1)
				coord_list_added(get_coord, x, y);
			y++;
		}
		x++;
	}
	choose_coord(matrix, get_coord, size);
	print_coord_list(get_coord);
	return (get_coord);
}

void			size_reset(t_size *size)
{
	size->piece_height = 0;
	size->piece_width = 0;
	size->map_x = 0;
	size->map_y = 0;
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
			matrix->map = reading_create_map(matrix->map, line, size);
			matrix->field = init_field(matrix, size, player);
			matrix->field = fill_field(matrix, size, player);
			print_field(matrix->field, size);
			dprintf(2, "RET : %d\n", check_zeros(matrix, size));
		}
		if (ft_isstrstr(line, "Piece"))
		{
			parse_piece_size(line, size);
			matrix->piece = alocate_matrix(size->piece_height, size->piece_width);
			matrix->piece = parse_piece(line, matrix->piece, size);
			player->symbol = player->first == 1 ? 'O' : 'X';
			get_coord = filler_algorithm(matrix, size, player);
			matrix_free(matrix, size);
		}
	}
	free(matrix);
	free(size);
	return (0);
}
