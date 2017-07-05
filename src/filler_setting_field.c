/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_setting_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:29:35 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/05 19:29:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static void			paste_digit_extension_func(t_matrix *matrix, int *x, \
	int *y, int *pace)
{
	if (((*x) + 1 < matrix->size_map_x) && (((*y) + 1 < matrix->size_map_y)))
	{
		if (matrix->field[(*x)][(*y) + 1] == 0)
			matrix->field[(*x)][(*y) + 1] = (*pace) + 1;
		if ((*y) != 0 && matrix->field[(*x)][(*y) - 1] == 0)
			matrix->field[(*x)][(*y) - 1] = (*pace) + 1;
		if ((*x) != 0 && matrix->field[(*x) - 1][(*y)] == 0)
			matrix->field[(*x) - 1][(*y)] = (*pace) + 1;
		if (matrix->field[(*x) + 1][(*y)] == 0)
			matrix->field[(*x) + 1][(*y)] = (*pace) + 1;
	}
	else if ((*x) == (matrix->size_map_x - 1) && (*y) == \
		(matrix->size_map_y - 2))
	{
		if (matrix->field[(*x)][(*y) - 1] == 0)
			matrix->field[(*x)][(*y) - 1] = (*pace) + 1;
		if (matrix->field[(*x) - 1][(*y)] == 0)
			matrix->field[(*x) - 1][(*y)] = (*pace) + 1;
		if (matrix->field[(*x)][(*y) + 1] == 0)
			matrix->field[(*x)][(*y) + 1] = (*pace) + 1;
	}
}

void				paste_digit(t_matrix *matrix, t_player *player, int *pace)
{
	int			x;
	int			y;

	x = 0;
	while (x < matrix->size_map_x)
	{
		y = 0;
		while (y < matrix->size_map_y)
		{
			if (matrix->field[x][y] == (*pace))
				paste_digit_extension_func(matrix, &x, &y, pace);
			y++;
		}
		x++;
	}
}
