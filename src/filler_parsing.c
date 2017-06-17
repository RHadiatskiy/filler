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
	if (*line)
		while (*line)
			if (ft_isdigit(*line++))
				break ;
	line--;
	if (ft_isdigit(*line))
		while (ft_isdigit(*line))
			map_size->x = map_size->x * 10 + (*line++ - '0');
	line++;
	if (ft_isdigit(*line))
		while (ft_isdigit(*line))
			map_size->y = map_size->y * 10 + (*line++ - '0');
}

void			parse_piece_size(char *line, t_piece_size *piece_size)
{
	int				i;

	i = 0;
	while (line[i])
		if (ft_isdigit(line[i++]))
			break ;
	if (line[i - 1])
		i--;
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			piece_size->height = piece_size->height * 10 + (line[i++] - '0');
	i++;
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			piece_size->width = piece_size->width * 10 + (line[i++] - '0');
}

char			**parse_piece(char *line, char **piece, \
	t_piece_size *piece_size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (get_next_line(0, &line) && (x < piece_size->height))
	{
		if (line[0] == '*' || line[0] == '.')
		{
			y = 0;
			i = 0;
			while (line[i] != '\n' && (y < piece_size->width))
				piece[x][y++] = line[i++];
			x++;
		}
	}
	return (piece);
}

t_matrix		*filler_parsing(t_matrix *matrix, t_map_size *map_size, \
	t_piece_size *piece_size, t_player *player)
{
	int				i;
	char			*line;

	i = 0;
	while (get_next_line(0, &line) && !ft_isstrstr(line, "Plateau"))
		if (ft_isstrstr(line, "exec p1") || ft_isstrstr(line, "exec p2"))
			parse_players(line, player);
	parse_map_size(line, map_size);
	matrix->map = alocate_matrix(map_size->x, map_size->y);
	matrix->map = reading_create_map(matrix->map, line, map_size, \
		piece_size);
	matrix->piece = alocate_matrix(piece_size->height, piece_size->width);
	matrix->piece = parse_piece(line, matrix->piece, piece_size);
	return (matrix);
}
