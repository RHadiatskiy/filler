/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:14:48 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/06 14:14:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualize.h"

void			parse_map_size(char *line, t_matrix *matrix)
{
	matrix->size_map_x = ft_atoi(&line[7]);
	matrix->size_map_y = ft_atoi(&line[7 + 1 + \
		ft_strlen(ft_itoa(matrix->size_map_x))]);
}

void			parse_players(char *line, t_player *player)
{
	int				i;
	char			*target;

	i = 0;
	if (ft_isstrstr(line, "exec p1"))
	{
		while (line[i++])
			if ((target = ft_strstr(line, "filler")))
				break ;
		if (*(target - 1) != '.')
			player->first = 1;
	}
	else if (ft_isstrstr(line, "exec p2"))
	{
		while (line[i++])
			if ((target = ft_strstr(line, "filler")))
				break ;
		if (*(target - 1) != '.')
			player->second = 1;
	}
}

void			parse_result(char *line, t_player *player)
{
	char	filler;

	filler = player->first == 1 ? 'O' : 'X';
	if (line[3] == filler)
		player->res_filler = ft_atoi(&line[9]);
	else
		player->res_enemy = ft_atoi(&line[9]);
}
