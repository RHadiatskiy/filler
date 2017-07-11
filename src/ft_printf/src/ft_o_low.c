/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:00:52 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:39:35 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_o_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_zero;
	char	*s_space;
	int		is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.zero == 1 && flags.minus == 0)
		s_zero = fillsmb('0', width - (prec > (int)ft_strlen(flags.args) \
			? prec : (int)ft_strlen(flags.args)));
	else
		s_zero = fillsmb('0', prec - (int)(ft_strlen(flags.args)));
	s_space = (flags.hash == 1 && ((int)(prec - \
		(int)(ft_strlen(flags.args)) < 1))) ? \
		(fillsmb(' ', (width - is_max - 1))) : \
			(fillsmb(' ', width - is_max));
	res_d = ft_strjoin(s_zero, flags.args);
	if (flags.hash == 1 && ((int)(prec - (int)(ft_strlen(flags.args)) < 1)) \
		&& (ft_strcmp(flags.args, "0") != 0))
		res_d = ft_strjoin("0", res_d);
	if (flags.zero == 0 || flags.minus == 1)
		flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	free(s_space);
	return (res_d);
}

int			ft_o_low(va_list elem, t_flags flags)
{
	int				width;
	int				prec;
	uintmax_t		r;

	r = check_lenght_unsigned(flags, va_arg(elem, uintmax_t));
	flags.args = ft_itoa_base_x(r, 8);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_o_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
