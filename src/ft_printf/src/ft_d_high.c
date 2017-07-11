/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:16:01 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/28 20:16:03 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t			check_d_lenght(t_flags flags, intmax_t d)
{
	if (flags.ll == 1)
		return ((long long)d);
	else if (flags.z == 1)
		return ((size_t)d);
	else if (flags.j == 1)
		return (d);
	else if (flags.l == 1)
		return ((long)d);
	else
		return ((long)d);
}

int					ft_d_high(va_list elem, t_flags flags)
{
	int			width;
	int			prec;
	long long	r;
	int			minus;

	minus = 0;
	r = check_d_lenght(flags, va_arg(elem, intmax_t));
	if (r < 0)
	{
		r *= -1;
		minus = 1;
	}
	flags.args = ft_itoa_base(r, 10);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_d_modify(width, prec, flags, minus);
	return (ft_printing(check_max(flags.args)));
}
