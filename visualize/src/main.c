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
	int			j;

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
	int			x;
	int			y;
	int			i;

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

void			print_map(char **map, t_player *player)
{
	int			i;
	int			j;
	char		filler;

	i = 0;
	filler = player->first == 1 ? 'O' : 'X';
	dprintf(2, "\n\n\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (uppersymb(map[i][j]) == filler)
				dprintf(2, "%s%c%s", GREEN, map[i][j++], RESET);
			else if (map[i][j] == '.')
				dprintf(2, "%s%c%s", WHITE, map[i][j++], RESET);
			else
				dprintf(2, "%s%c%s", RED, map[i][j++], RESET);
		}
		dprintf(2, "\n");
		i++;
	}
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
	ft_printf("\nTOTAL:\n%sFILLER :\t%jd%s\n%sENEMY :\t\t%jd%s\n\n", GREEN, \
		player->res_filler, RESET, RED, player->res_enemy, RESET);
	ft_printf("\n%sWINNER IS %s!%s\n\n", GREEN, \
		player->res_filler > player->res_enemy ? "FILLER" : "ENEMY", RESET);
	free(matrix);
	free(player);
}
