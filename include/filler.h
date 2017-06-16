/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:36:51 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/13 19:36:53 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct	s_piece_size
{
	size_t			height;
	size_t			width;
}				t_piece_size;

typedef struct	s_matrix_size
{
	size_t			x;
	size_t			y;
}				t_matrix_size;

int				ft_isstrstr(char *big, char *little);
t_matrix_size	*initial_matrix_size(void);
t_piece_size	*initial_piece_size(void);
void			parse_matrix_size(char *line, t_matrix_size *matrix_size);
void			parse_piece_size(char *line, t_piece_size *piece_size);

#endif
