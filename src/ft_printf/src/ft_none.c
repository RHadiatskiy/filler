/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_none.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:37:02 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/27 12:37:03 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			print_space(t_flags flags)
{
	char	*space;

	space = (flags.zero == 1 && flags.minus == 0) ? \
	fillsmb('0', flags.get_width - 1) : fillsmb(' ', flags.get_width - 1);
	write(1, space, ft_strlen(space));
	free(space);
	return (ft_strlen(space));
}

int			ft_none(va_list elem, t_flags flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	(void)elem;
	if (flags.minus == 0)
		count += print_space(flags);
	while (flags.str[i++])
	{
		if ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && \
			flags.str[i] != 'l' && flags.str[i] != 'h' && flags.str[i] != 'j' \
			&& flags.str[i] != 'z' && flags.str[i] != ' ' && \
			flags.str[i] != '.' && flags.str[i] != '-' && flags.str[i] != '+' \
			&& flags.str[i] != '#' && !ft_isdigit(flags.str[i]))
		{
			count += write(1, &flags.str[i++], 1);
			if (flags.minus == 1)
				count += print_space(flags);
			while ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && \
				flags.str[i])
				count += write(1, &flags.str[i++], 1);
		}
	}
	return (count);
}
