/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:37:42 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/05 17:37:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void			matrix_free(t_matrix *matrix)
{
	size_t		x;

	x = matrix->size_map_x - 1;
	if (matrix->map && matrix->field)
	{
		while (matrix->size_map_x && x)
		{
			free(matrix->map[matrix->size_map_x--]);
			free(matrix->field[x--]);
		}
		free(matrix->map);
		free(matrix->field);
	}
	if (matrix->piece)
	{
		while (matrix->size_piece_height)
			free(matrix->piece[matrix->size_piece_height--]);
		free(matrix->piece);
	}
}

void			coordinats_free(t_get_coord **get_coord)
{
	t_get_coord *prev;

	prev = NULL;
	while ((*get_coord)->next)
	{
		prev = (*get_coord);
		(*get_coord) = (*get_coord)->next;
		prev->x = 0;
		prev->y = 0;
		prev->n = 0;
		free(prev);
	}
	free((*get_coord));
}
