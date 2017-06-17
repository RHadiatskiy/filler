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

t_map_size	*initial_map_size(void)
{
	t_map_size		*map_size;

	if (!(map_size = (t_map_size *)malloc(sizeof(t_map_size))))
		return (NULL);
	map_size->x = 0;
	map_size->y = 0;
	return (map_size);
}

t_piece_size	*initial_piece_size(void)
{
	t_piece_size	*piece_size;

	if (!(piece_size = (t_piece_size *)malloc(sizeof(t_piece_size))))
		return (NULL);
	piece_size->height = 0;
	piece_size->width = 0;
	return (piece_size);
}

t_player		*initial_player(void)
{
	t_player		*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->first = 0;
	player->second = 0;
	return (player);
}

t_matrix		*initial_matrix(void)
{
	t_matrix		*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->map = NULL;
	matrix->piece = NULL;
	return (matrix);
}

void			filler_initial(t_matrix *matrix, t_map_size *map_size, \
	t_piece_size *piece_size, t_player *player)
{
	map_size = initial_map_size();
	piece_size = initial_piece_size();
	player = initial_player();
	matrix = initial_matrix();
}
