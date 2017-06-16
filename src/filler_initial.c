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