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


int				**init_field(t_matrix *matrix, t_size *size, t_player *player)
{
	int			x;
	int			y;
	char		enemy;
	int			**field;

	x = 0;
	field = alocate_field(size->map_x, size->map_y);
	enemy = player->symbol == 'O' ? 'X' : 'O';
	while (x < size->map_x)
	{
		y = 0;
		while (y < size->map_y)
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

int				check_zeros(t_matrix *matrix, t_size *size)
{
	int			x;
	int			y;

	x = 0;
	while (x < size->map_x)
	{
		y = 0;
		while (y < size->map_y)
		{
			if (matrix->field[x][y] == 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void			paste_digit(t_matrix *matrix, t_size *size, t_player *player, int *pace)
{
	int			x;
	int			y;

	x = 0;
	while (x < size->map_x)
	{
		y = 0;
		while (y < size->map_y)
		{
			if (matrix->field[x][y] == (*pace))
			{
				if (x == 0 && y == 0 && (x + 1 < size->map_x) && (y + 1 < size->map_y))
				{
					if (matrix->field[x][y + 1] == 0)
						matrix->field[x][y + 1] = (*pace) + 1;
					if (matrix->field[x + 1][y] == 0)
						matrix->field[x + 1][y] = (*pace) + 1;
				}
				else if (x == 0 && y > 0 && (x + 1 < size->map_x) && ((y + 1 < size->map_y)))
				{
					if (matrix->field[x][y + 1] == 0)
						matrix->field[x][y + 1] = (*pace) + 1;
					if (matrix->field[x][y - 1] == 0)
						matrix->field[x][y - 1] = (*pace) + 1;
					if (matrix->field[x + 1][y] == 0)
						matrix->field[x + 1][y] = (*pace) + 1;
				}
				else if (x > 0 && y == 0 && (x + 1 < size->map_x) && ((y + 1 < size->map_y)))
				{
					if (matrix->field[x][y + 1] == 0)
						matrix->field[x][y + 1] = (*pace) + 1;
					if (matrix->field[x - 1][y] == 0)
						matrix->field[x - 1][y] = (*pace) + 1;
					if (matrix->field[x + 1][y] == 0)
						matrix->field[x + 1][y] = (*pace) + 1;
				}
				else if (x > 0 && y > 0 && (x + 1 < size->map_x) && ((y + 1 < size->map_y)))
				{
					if (matrix->field[x][y + 1] == 0)
						matrix->field[x][y + 1] = (*pace) + 1;
					if (matrix->field[x][y - 1] == 0)
						matrix->field[x][y - 1] = (*pace) + 1;
					if (matrix->field[x - 1][y] == 0)
						matrix->field[x - 1][y] = (*pace) + 1;
					if (matrix->field[x + 1][y] == 0)
						matrix->field[x + 1][y] = (*pace) + 1;
				}
				else if (x == (size->map_x - 1) && y == (size->map_y - 2))
				{
					if (matrix->field[x][y - 1] == 0)
						matrix->field[x][y - 1] = (*pace) + 1;
					if (matrix->field[x - 1][y] == 0)
						matrix->field[x - 1][y] = (*pace) + 1;
					if (matrix->field[x][y + 1] == 0)
						matrix->field[x][y + 1] = (*pace) + 1;
				}
			}
			y++;
		}
		x++;
	}
}

int				**fill_field(t_matrix *matrix, t_size *size, t_player *player)
{
	int			pace;

	pace = 1;
	while (check_zeros(matrix, size))
	{
		paste_digit(matrix, size, player, &pace);
		pace++;
	}
	return (matrix->field);
}

void			print_field(int **matrix, t_size *size)
{
	int			i;
	int			j;

	i = 0;
	dprintf(2, "\n");
	while (i < size->map_x)
	{
		j = 0;
		while (j < size->map_y)
		{
			if (matrix[i][j] == 1)
				dprintf(2, "%s%3d%s", RED, matrix[i][j++], RESET);
			else
				dprintf(2, "%3d", matrix[i][j++]);
		}
		dprintf(2, "\n");
		i++;
	}
}
