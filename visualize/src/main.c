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

void			print_map(char **map, t_player *player)
{
	size_t		i;
	size_t		j;
	char		filler;

	i = 0;
	filler = player->first == 1 ? 'O' : 'X';
	ft_printf("\n\033[6;0H");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (uppersymb(map[i][j]) == filler)
				ft_printf("%s%c%s", GREEN, map[i][j++], RESET);
			else if (map[i][j] == '.')
				ft_printf("%s%c%s", WHITE, map[i][j++], RESET);
			else
				ft_printf("%s%c%s", RED, map[i][j++], RESET);
		}
		ft_printf("\n");
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
	ft_printf("\n%sFILLER :\t%jd%s\n%sENEMY :\t\t%jd%s\n\n", GREEN, \
		player->res_filler, RESET, RED, player->res_enemy, RESET);
	if (player->res_filler > player->res_enemy)
		ft_printf("\n%sWINNER IS %s!%s\n\n", GREEN, "FILLER", RESET);
	else
		ft_printf("\n%sWINNER IS %s!%s\n\n", RED, "ENEMY", RESET);
	free(matrix);
	free(player);
}
