/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:39:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/13 19:39:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_matrix_size	*initial_matrix_size(void)
{
	t_matrix_size	*matrix_size;

	if (!(matrix_size = (t_matrix_size *)malloc(sizeof(t_matrix_size))))
		return (NULL);
	matrix_size->x = 0;
	matrix_size->y = 0;
	return (matrix_size);
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

void			parse_matrix_size(char *line, t_matrix_size *matrix_size)
{
	while (get_next_line(0, &line) && !flr_strstr(line, "Plateau"))
		;
	while (*line)
		if (ft_isdigit(*line++))
			break ;
	*line--;
	while (ft_isdigit(*line))
		matrix_size->x = matrix_size->x * 10 + (*line++ - '0');
	*line++;
	while (ft_isdigit(*line))
		matrix_size->y = matrix_size->y * 10 + (*line++ - '0');
}

void			parse_piece_size(char *line, t_piece_size *piece_size)
{
	int				i;

	i = 0;
	while (line[i])
		if (ft_isdigit(line[i++]))
			break ;
	line[i--];
	while (ft_isdigit(line[i]))
		piece_size->height = piece_size->height * 10 + (line[i++] - '0');
	line[i++];
	while (ft_isdigit(line[i]))
		piece_size->width = piece_size->width * 10 + (line[i++] - '0');
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

char			**reading_create_map(char **matrix, char *line, t_matrix_size *matrix_size, t_piece_size *piece_size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (get_next_line(0, &line) && !flr_strstr(line, "Piece") && x < matrix_size->x)
	{
		if (line[0] == '0')
		{
			y = 0;
			i = 0;
			while (line[i++] != ' ')
				;
			while (line[i] != '\n' && y < matrix_size->y)
				matrix[x][y++] = line[++i];
			x++;
		}
	}
	parse_piece_size(line, piece_size);
	return (matrix);
}

int				main(void)
{
	char			**matrix;
	char			*line;
	t_matrix_size	*matrix_size;
	t_piece_size	*piece_size;
	int 			i;

	i = 0;
	matrix_size = initial_matrix_size();
	piece_size = initial_piece_size();
	parse_matrix_size(line, matrix_size);

	matrix = alocate_matrix(matrix_size->x, matrix_size->y);
	matrix = reading_create_map(matrix, line, matrix_size, piece_size);

	while (matrix[i])
		printf("%s\n", matrix[i++]);

	// printf("x : %zu\n", matrix_size->x);
	// printf("y : %zu\n", matrix_size->y);

	// printf("height : %zu\n", piece_size->height);
	// printf("width : %zu\n", piece_size->width);


	free(matrix_size);
	free(piece_size);
	return (0);
}
