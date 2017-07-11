/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:12:34 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/05 17:12:36 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void			print_coordinats(size_t x, size_t y)
{
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
}

void			print_field(int **matrix, t_matrix *size)
{
	size_t		i;
	size_t		j;

	i = 0;
	dprintf(2, "\n");
	while (i < size->size_map_x)
	{
		j = 0;
		while (j < size->size_map_y)
		{
			if (matrix[i][j] == 1)
				dprintf(2, "%s%3d%s", RED, matrix[i][j++], RESET);
			else
				dprintf(2, "%3d", matrix[i][j++]);
		}
		dprintf(2, "\n");
		i++;
	}
}

void			print_maxtrix(char **matrix)
{
	size_t		i;
	size_t		j;

	i = 0;
	dprintf(2, "\n");
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
				dprintf(2, "%s%c%s", RED, matrix[i][j++], RESET);
			else
				dprintf(2, "%c", matrix[i][j++]);
		}
		dprintf(2, "\n");
		i++;
	}
}
