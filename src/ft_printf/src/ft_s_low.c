/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:33:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:41:15 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_s_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flags.precision == 1)
	{
		res_d = (char *)malloc(sizeof(char) * prec + 1);
		while (prec > i)
			res_d[i++] = flags.args[j++];
		res_d[i] = '\0';
	}
	else
		res_d = ft_strdup(flags.args);
	if (flags.zero == 1 && flags.minus != 1)
		s_space = fillsmb('0', width - ft_strlen(res_d));
	else
		s_space = fillsmb(' ', width - ft_strlen(res_d));
	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
	(res_d = ft_strjoin(s_space, res_d));
	free(s_space);
	return (res_d);
}

int			ft_s_low(va_list elem, t_flags flags)
{
	int		width;
	int		prec;

	if (flags.l == 1)
		return (ft_s_high(elem, flags));
	flags.args = (char *)va_arg(elem, void *);
	prec = flags.get_precision;
	width = flags.get_width;
	if (flags.args == NULL)
		flags.args = ft_strdup("(null)");
	return (ft_printing(spec_s_modify(width, prec, flags)));
}
