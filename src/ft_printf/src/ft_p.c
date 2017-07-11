/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:28:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 12:28:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_p_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_zero;
	char	*s_space;
	int		is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.precision == 0 && flags.width == 1)
	{
		s_zero = flags.zero == 0 ? fillsmb('0', 0) : \
			fillsmb('0', width - is_max - 2);
		s_space = flags.zero == 0 ? fillsmb(' ', width - is_max - 2) : \
			fillsmb(' ', 0);
	}
	else
	{
		s_zero = fillsmb('0', prec - ft_strlen(flags.args));
		s_space = fillsmb(' ', (width - is_max - 2));
	}
	res_d = ft_strjoin(s_zero, flags.args);
	res_d = ft_strjoin("0x", res_d);
	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}

int			ft_p(va_list elem, t_flags flags)
{
	intmax_t	p;
	int			width;
	int			prec;

	p = va_arg(elem, intmax_t);
	flags.args = ft_itoa_base(p, 16);
	if ((ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	width = flags.get_width;
	prec = flags.get_precision;
	flags.args = spec_p_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
