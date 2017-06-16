#include "../include/filler.h"

void			parse_matrix_size(char *line, t_matrix_size *matrix_size)
{
	while (get_next_line(0, &line) && !ft_isstrstr(line, "Plateau"))
		;
	if (*line)
		while (*line)
			if (ft_isdigit(*line++))
				break ;
	*line--;
	if (ft_isdigit(*line))
		while (ft_isdigit(*line))
			matrix_size->x = matrix_size->x * 10 + (*line++ - '0');
	*line++;
	if (ft_isdigit(*line))
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
	if (line[i - 1])
		line[i--];
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			piece_size->height = piece_size->height * 10 + (line[i++] - '0');
	line[i++];
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			piece_size->width = piece_size->width * 10 + (line[i++] - '0');
}
