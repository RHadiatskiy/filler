/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:01:27 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/16 17:01:28 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

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

void			parse_map_size(char *line, t_matrix *matrix)
{
	matrix->size_map_x = ft_atoi(&line[7]);
	matrix->size_map_y = ft_atoi(&line[7 + 1 + \
		ft_strlen(ft_itoa(matrix->size_map_x))]);
}

void			parse_piece_size(char *line, t_matrix *matrix)
{
	matrix->size_piece_height = ft_atoi(&line[5]);
	matrix->size_piece_width = ft_atoi(&line[5 + 1 + \
		ft_strlen(ft_itoa(matrix->size_piece_height))]);
}

char			**parse_piece(char *line, char **piece, \
	t_matrix *matrix)
{
	size_t		x;
	size_t		y;
	size_t		i;

	x = 0;
	while (x < matrix->size_piece_height && get_next_line(0, &line))
	{
		if (line[0] == '*' || line[0] == '.')
		{
			y = 0;
			i = 0;
			while (y < matrix->size_piece_width)
				piece[x][y++] = line[i++];
		}
		x++;
	}
	return (piece);
}

void			parse_last_pace_of_enemy(char *line, t_player *player)
{
	char		enemy;

	enemy = player->symbol == 'O' ? 'X' : 'O';	
	if (line[6] == enemy)
	{
		player->enemy_last_x = ft_atoi(&line[11]);
		player->enemy_last_y = ft_atoi(&line[11 + 2 + \
			ft_strlen(ft_itoa(player->enemy_last_x))]);
	}
}