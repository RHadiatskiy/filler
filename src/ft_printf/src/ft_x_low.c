/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:57:49 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/22 19:57:51 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_x_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_zero;
	char	*s_space;
	int		is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.zero == 0 || flags.precision == 1 || flags.minus == 1)
		s_zero = fillsmb('0', prec - ft_strlen(flags.args));
	else if (flags.zero == 1 && flags.precision == 0)
		s_zero = fillsmb('0', width - (flags.hash == 1 ? 2 : 0) - \
			ft_strlen(flags.args));
	res_d = ft_strjoin(s_zero, flags.args);
	if (flags.hash == 1 && (ft_strcmp("0", flags.args)) != 0 && \
		(ft_strcmp("", flags.args)) != 0)
		res_d = ft_strjoin("0x", res_d);
	s_space = (flags.hash == 1 && ((int)(prec - \
		(int)(ft_strlen(res_d)) < 1))) ? \
		(fillsmb(' ', (width - is_max - 2))) : \
			(fillsmb(' ', width - is_max));
	if (flags.zero == 0 || flags.minus == 1)
		flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	free(s_space);
	return (res_d);
}

int			ft_x_low(va_list elem, t_flags flags)
{
	int				width;
	int				prec;
	intmax_t		r;

	r = check_lenght_unsigned(flags, va_arg(elem, uintmax_t));
	flags.args = ft_itoa_base_x(r, 16);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_x_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
