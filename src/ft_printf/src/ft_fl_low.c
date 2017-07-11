/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fl_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:59:01 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/08 17:14:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_fl_low(va_list elem, t_flags flags)
{
	double		r;

	r = va_arg(elem, double);
	flags.args = ft_itoa_base(r, 10);
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	return (ft_printing(flags.args));
}
