/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:51:09 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/22 18:51:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			spec_c_modify(int width, t_flags flags, char c)
{
	char		*s_space;
	int			n;

	n = 0;
	if (flags.zero == 1 && flags.minus != 1)
		s_space = fillsmb('0', width - 1);
	else
		s_space = fillsmb(' ', width - 1);
	if (flags.minus == 1)
	{
		n += write(1, &c, 1);
		n += write(1, s_space, ft_strlen(s_space));
	}
	else
	{
		n += write(1, s_space, ft_strlen(s_space));
		n += write(1, &c, 1);
	}
	free(s_space);
	return (n);
}

int			ft_c_low(va_list elem, t_flags flags)
{
	int			width;
	wchar_t		c;

	c = (wchar_t)va_arg(elem, wchar_t);
	width = flags.get_width;
	if (flags.l == 1)
		return (choose_mask(c));
	return (spec_c_modify(width, flags, c));
}
