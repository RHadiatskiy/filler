/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:24:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:42:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t	check_lenght_unsigned(t_flags flags, uintmax_t d)
{
	if (flags.ll == 1)
		return ((unsigned long long)d);
	else if (flags.z == 1)
		return ((size_t)d);
	else if (flags.j == 1)
		return ((uintmax_t)d);
	else if (flags.l == 1)
		return ((unsigned long)d);
	else if (flags.h == 1)
		return ((unsigned short)d);
	else if (flags.hh == 1)
		return ((unsigned char)d);
	else
		return ((unsigned int)d);
}

char		*spec_u_modify(int width, int prec, t_flags flags, int minus)
{
	char			*res_d;
	char			*s_zero;
	char			*s_space;
	int				is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.zero == 1 && flags.minus == 0 && flags.precision == 0)
		s_zero = fillsmb('0', width - (prec > (int)ft_strlen(flags.args) ? \
			prec : (int)ft_strlen(flags.args)));
	else
		s_zero = fillsmb('0', prec - (int)(ft_strlen(flags.args)));
	s_space = (minus == 0 && flags.plus == 0) ? \
		(fillsmb(' ', width - is_max)) : (fillsmb(' ', (width - is_max - 1)));
	res_d = ft_strjoin(s_zero, flags.args);
	if (flags.zero == 0 || flags.minus == 1 || flags.precision == 1)
		flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	free(s_zero);
	free(s_space);
	return (res_d);
}

int			ft_u_low(va_list elem, t_flags flags)
{
	int				width;
	int				prec;
	uintmax_t		r;
	int				minus;

	minus = 0;
	r = check_lenght_unsigned(flags, va_arg(elem, uintmax_t));
	flags.args = ft_itoa_base_x(r, 10);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_u_modify(width, prec, flags, minus);
	return (ft_printing(flags.args));
}
