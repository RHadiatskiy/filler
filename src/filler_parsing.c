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

void			parse_map_size(char *line, t_map_size *map_size)
{
	map_size->x = ft_atoi(&line[7]);
	map_size->y = ft_atoi(&line[7 + 1 + ft_strlen(ft_itoa(map_size->x))]);
}

void			parse_piece_size(char *line, t_piece_size *piece_size)
{
	piece_size->height = ft_atoi(&line[5]);
	piece_size->width = ft_atoi(&line[5 + 1 + ft_strlen(ft_itoa(piece_size->height))]);
}

char			**parse_piece(char *line, char **piece, \
	t_piece_size *piece_size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < piece_size->height && get_next_line(0, &line))
	{
		if (line[0] == '*' || line[0] == '.')
		{
			y = 0;
			i = 0;
			while (y < piece_size->width)
				piece[x][y++] = line[i++];
		}
		x++;
	}
	return (piece);
}
