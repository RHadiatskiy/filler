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

void			parse_map_size(char *line, t_size *size)
{
	size->map_x = ft_atoi(&line[7]);
	size->map_y = ft_atoi(&line[7 + 1 + ft_strlen(ft_itoa(size->map_x))]);
}

void			parse_piece_size(char *line, t_size *size)
{
	size->piece_height = ft_atoi(&line[5]);
	size->piece_width = ft_atoi(&line[5 + 1 + ft_strlen(ft_itoa(size->piece_height))]);
}

char			**parse_piece(char *line, char **piece, \
	t_size *size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < size->piece_height && get_next_line(0, &line))
	{
		if (line[0] == '*' || line[0] == '.')
		{
			y = 0;
			i = 0;
			while (y < size->piece_width)
				piece[x][y++] = line[i++];
		}
		x++;
	}
	return (piece);
}
