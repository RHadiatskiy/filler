/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:54:59 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/04 20:55:01 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ucodelen(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c > 127 && c <= 2047)
		return (2);
	else if (c > 2047 && c <= 65535)
		return (3);
	else
		return (4);
}

int			choose_mask_f(unsigned int value, int prec)
{
	unsigned int	mask[4];

	mask[0] = 0;
	mask[1] = 49280;
	mask[2] = 14712960;
	mask[3] = 4034953344;
	g_uprec[0] = take_mask_0;
	g_uprec[1] = take_mask_1;
	g_uprec[2] = take_mask_2;
	g_uprec[3] = take_mask_3;
	return ((*g_uprec[prec - 1])(value, mask[prec - 1]));
}

int			print_u_prec(wchar_t *s, int prec)
{
	int		i;
	int		sum;
	int		n;

	n = 0;
	sum = prec;
	i = 0;
	while (s[i] && prec > i)
	{
		if (ucodelen(s[i]) <= sum)
		{
			sum -= ucodelen(s[i]);
			n += choose_mask(s[i]);
		}
		else if (sum > 0)
			break ;
		i++;
	}
	return (n);
}

char		*fill_space(wchar_t *s, t_flags flags)
{
	char		*space;
	int			wise;

	wise = flags.get_width - (flags.precision == 1 ? \
		len_u_prec(s, flags.get_precision) : ft_strlen_u(s));
	if (flags.zero == 1)
		space = fillsmb('0', wise);
	else
		space = fillsmb(' ', wise);
	return (space);
}

int			ft_s_high(va_list elem, t_flags flags)
{
	wchar_t		*s;
	int			i;
	int			n;
	char		*space;

	n = 0;
	i = 0;
	s = (wchar_t *)va_arg(elem, wchar_t *);
	if (s == NULL)
	{
		flags.args = ft_strdup("(null)");
		return (ft_printing(spec_s_modify(flags.get_width, \
			flags.get_precision, flags)));
	}
	space = fill_space(s, flags);
	if (flags.minus == 0)
		n += ft_printing(space);
	if (flags.precision == 1)
		n += print_u_prec(s, flags.get_precision);
	else
		while (s[i])
			n += choose_mask(s[i++]);
	if (flags.minus == 1)
		n += ft_printing(space);
	return (n);
}
