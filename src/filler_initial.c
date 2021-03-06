/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_initial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:01:45 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/16 17:01:48 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_player		*initial_player(void)
{
	t_player		*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->first = 0;
	player->second = 0;
	player->symbol = 0;
	player->enemy_last_x = 0;
	player->enemy_last_y = 0;
	return (player);
}

t_matrix		*initial_matrix(void)
{
	t_matrix		*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->map = NULL;
	matrix->field = 0;
	matrix->piece = NULL;
	matrix->size_map_x = 0;
	matrix->size_map_y = 0;
	matrix->size_piece_height = 0;
	matrix->size_piece_width = 0;
	return (matrix);
}

t_get_coord		*initial_get_coord_list(void)
{
	t_get_coord		*initial;

	if (!(initial = (t_get_coord *)malloc(sizeof(t_get_coord))))
		return (NULL);
	initial->x = 0;
	initial->y = 0;
	initial->n = 0;
	initial->next = NULL;
	return (initial);
}
