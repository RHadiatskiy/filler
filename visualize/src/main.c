/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:19:50 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/06 13:19:52 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualize.h"

void			map_free(t_matrix *matrix)
{
	if (matrix->map)
	{
		while (matrix->size_map_x)
			free(matrix->map[matrix->size_map_x--]);
		free(matrix->map);
	}
}

char			**alocate_matrix(size_t height, size_t width)
{
	char		**matrix;
	size_t		j;

	j = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * height + 1)))
		return (NULL);
	while (j < height)
	{
		if (!(matrix[j] = (char *)malloc(sizeof(char) * width + 1)))
			return (NULL);
		matrix[j++][width] = '\0';
	}
	matrix[height] = NULL;
	return (matrix);
}

char			**reading_create_map(char **matrix, char *line, t_matrix *size)
{
	size_t		x;
	size_t		y;
	size_t		i;

	x = 0;
	while (x < size->size_map_x && get_next_line(0, &line))
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			i--;
			while (line[i] && y < size->size_map_y)
				matrix[x][y++] = line[++i];
			x++;
		}
	}
	return (matrix);
}

void			visualize_printing_map_extension(char *line, t_matrix *matrix, \
	t_player *player)
{
	parse_map_size(line, matrix);
	matrix->map = reading_create_map(alocate_matrix(\
	matrix->size_map_x, matrix->size_map_y), line, matrix);
	print_map(matrix->map, player);
	map_free(matrix);
}

int				main(void)
{
	t_matrix		*matrix;
	t_player		*player;
	char			*line;

	matrix = initial_matrix();
	player = initial_player();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isstrstr(line, "exec p1") || ft_isstrstr(line, "exec p2"))
			parse_players(line, player);
		if (ft_isstrstr(line, "Plateau"))
			visualize_printing_map_extension(line, matrix, player);
		if (ft_isstrstr(line, "=="))
			parse_result(line, player);
	}
	print_result(player);
	free(matrix);
	free(player);
}
