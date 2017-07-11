/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:40 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 14:34:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t	check_lenght_o_unsigned(t_flags flags, uintmax_t d)
{
	if (flags.ll == 1)
		return ((unsigned long long)d);
	else if (flags.z == 1)
		return ((size_t)d);
	else if (flags.j == 1)
		return ((uintmax_t)d);
	else if (flags.l == 1)
		return ((unsigned long)d);
	else
		return ((unsigned long)d);
}

int			ft_o_high(va_list elem, t_flags flags)
{
	int				width;
	int				prec;
	uintmax_t		r;

	r = check_lenght_o_unsigned(flags, va_arg(elem, uintmax_t));
	flags.args = ft_itoa_base_x(r, 8);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_o_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
