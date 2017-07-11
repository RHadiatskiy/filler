/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:34:37 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:40:12 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_none_double(va_list elem, t_flags flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	(void)elem;
	while (flags.str[i])
	{
		if ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && \
			flags.str[i] != 'l' && flags.str[i] != 'h' && \
			flags.str[i] != 'j' && flags.str[i] != 'z' && \
			flags.str[i] != ' ' && flags.str[i] != '.' && \
			flags.str[i] != '-' && flags.str[i] != '+' && \
			flags.str[i] != '#' && !ft_isdigit(flags.str[i]))
			while ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && \
				flags.str[i])
				count += write(1, &flags.str[i++], 1);
		else
			i++;
	}
	return (count);
}

int			ft_percent(va_list elem, t_flags flags)
{
	int		i;
	int		ret;
	int		width;

	i = 1;
	ret = 0;
	(void)elem;
	width = flags.get_width;
	if ((ret = (ft_none_double(elem, flags))) == 0)
	{
		while (flags.str[i] == ' ' && flags.str[i])
			i++;
		if (flags.minus == 1)
			write(1, "%", 1);
		while (width-- > 1)
			(flags.zero == 1 && flags.minus == 0) ? (write(1, "0", 1)) : \
			(write(1, " ", 1));
		if (flags.minus != 1)
			write(1, "%", 1);
		return (flags.width == 1 && flags.get_width != 0 ? flags.get_width : 1);
	}
	else
		return (ret);
}
