/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_initial.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:09:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/06 14:09:13 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualize.h"

t_matrix		*initial_matrix(void)
{
	t_matrix		*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->map = NULL;
	matrix->size_map_x = 0;
	matrix->size_map_y = 0;
	return (matrix);
}

t_player		*initial_player(void)
{
	t_player		*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->first = 0;
	player->second = 0;
	player->res_filler = 0;
	player->res_enemy = 0;
	player->flag = 0;
	return (player);
}
