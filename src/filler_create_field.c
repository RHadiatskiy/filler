/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_create_field.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 20:08:44 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/01 20:08:46 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int				**alocate_field(size_t height, size_t width)
{
	int			**matrix;
	int			j;

	j = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * height)))
		return (0);
	while (j < height)
	{
		if (!(matrix[j++] = (int *)malloc(sizeof(int) * width)))
			return (0);
	}
	return (matrix);
}

int				**init_field(t_matrix *matrix, t_player *player)
{
	int			x;
	int			y;
	char		enemy;
	int			**field;

	x = 0;
	field = alocate_field(matrix->size_map_x, matrix->size_map_y);
	enemy = player->symbol == 'O' ? 'X' : 'O';
	while (x < matrix->size_map_x)
	{
		y = 0;
		while (y < matrix->size_map_y)
		{
			if (uppersymb(matrix->map[x][y]) == enemy)
				field[x][y] = 1;
			else
				field[x][y] = 0;
			y++;
		}
		x++;
	}
	return (field);
}

int				check_zeros(t_matrix *matrix)
{
	int			x;
	int			y;

	x = 0;
	while (x < matrix->size_map_x)
	{
		y = 0;
		while (y < matrix->size_map_y)
		{
			if (matrix->field[x][y] == 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int				**set_cell_of_field(t_matrix *matrix, t_player *player)
{
	int			pace;

	pace = 1;
	matrix->field = init_field(matrix, player);
	while (check_zeros(matrix))
	{
		paste_digit(matrix, player, &pace);
		pace++;
	}
	return (matrix->field);
}
