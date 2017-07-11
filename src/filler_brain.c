/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_brain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:40:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/05 17:40:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int				check_sum(t_matrix *matrix, size_t x, size_t y)
{
	int			i;
	int			j;
	int			sum;

	i = 0;
	sum = 0;
	while (i < matrix->size_piece_height)
	{
		j = 0;
		while (j < matrix->size_piece_width)
		{
			if (matrix->piece[i][j] == '*')
				sum += matrix->field[x + i][y + j];
			j++;
		}
		i++;
	}
	return (sum);
}

void			choose_coord(t_matrix *matrix, t_get_coord *get_coord)
{
	t_get_coord	*tmp;
	int			sum;
	size_t		x;
	size_t		y;

	x = get_coord->x;
	y = get_coord->y;
	sum = check_sum(matrix, x, y);
	tmp = get_coord;
	while (tmp->next)
	{
		if (sum > (check_sum(matrix, tmp->next->x, tmp->next->y)))
		{
			x = tmp->next->x;
			y = tmp->next->y;
		}
		tmp = tmp->next;
	}
	print_coordinats(x, y);
}

int				check_enemy(t_matrix *matrix, int x, int y, char enemy)
{
	int			i;
	int			j;

	i = 0;
	while (i < matrix->size_piece_height)
	{
		j = 0;
		while (j < matrix->size_piece_width)
		{
			if (((uppersymb(matrix->map[x + i][y + j]) == enemy) && \
				matrix->piece[i][j] == '*'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				check_connect(t_matrix *matrix, int x, int y, \
	t_player *player)
{
	int			overlap;
	size_t		i;
	size_t		j;
	char		enemy;

	overlap = 0;
	i = 0;
	enemy = player->symbol == 'O' ? 'X' : 'O';
	while (i < matrix->size_piece_height)
	{
		j = 0;
		while (j < matrix->size_piece_width)
		{
			if (((uppersymb(matrix->map[x + i][y + j]) == player->symbol) \
				&& matrix->piece[i][j] == '*') && \
				check_enemy(matrix, x, y, enemy))
				overlap++;
			j++;
		}
		i++;
	}
	return (overlap);
}

void			filler_algorithm(t_matrix *matrix, t_player *player)
{
	t_get_coord		*get_coord;
	size_t			x;
	size_t			y;

	get_coord = initial_get_coord_list();
	x = 0;
	player->symbol = player->first == 1 ? 'O' : 'X';
	while (x <= (matrix->size_map_x - matrix->size_piece_height))
	{
		y = 0;
		while (y <= (matrix->size_map_y - matrix->size_piece_width))
		{
			if (check_connect(matrix, x, y, player) == 1)
				coord_list_added(get_coord, x, y);
			y++;
		}
		x++;
	}
	choose_coord(matrix, get_coord);
	coordinats_free(&get_coord);
}
