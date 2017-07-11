/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:28:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:43:05 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_parse(va_list elem, t_flags *flags)
{
	int		i;

	i = 1;
	parse_flags(elem, flags->str, flags);
	parse_length(elem, flags->str, flags);
	while (flags->str[i] != 'l' && flags->str[i] != 'h' && \
		flags->str[i] != 'j' && flags->str[i] != 'z' \
		&& flags->str[i] && \
		ft_strlenchr(SPECIFICATE, flags->str[i]) == -1)
		parse_width(elem, &i, flags);
	flags->specificate = flags->str[ft_strlen(flags->str) - 1];
	if (flags->get_width < 0)
	{
		flags->get_width *= -1;
		flags->minus = 1;
	}
	if (flags->get_precision < 0)
		flags->precision = 0;
}

void		parse_flags(va_list elem, char *str, t_flags *flags)
{
	int		i;

	i = 1;
	(void)elem;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == ' ' || \
			str[i] == '+' || str[i] == '-' || \
			str[i] == '#')
		{
			if (str[i] == '0' && !ft_isdigit(str[i - 1]) && \
				str[i - 1] != '.')
				flags->zero = 1;
			else if (str[i] == ' ')
				flags->space = 1;
			else if (str[i] == '+')
				flags->plus = 1;
			else if (str[i] == '-')
				flags->minus = 1;
			else if (str[i] == '#')
				flags->hash = 1;
		}
		i++;
	}
}

void		parse_precision(va_list elem, int *i, t_flags *flags)
{
	flags->precision = 1;
	flags->get_precision = 0;
	(*i)++;
	if (flags->str[(*i)] == '*')
	{
		flags->asterix_pre = 1;
		flags->get_precision = va_arg(elem, int);
		(*i)++;
	}
	else if (ft_isdigit(flags->str[(*i)]))
		while (ft_isdigit(flags->str[(*i)]))
			flags->get_precision = flags->get_precision * 10 + \
		(flags->str[(*i)++] - '0');
}

void		parse_width(va_list elem, int *i, t_flags *flags)
{
	if (flags->str[(*i)] == '.')
		parse_precision(elem, i, flags);
	else if (flags->str[(*i)] == '0' && (!ft_isdigit(flags->str[(*i) - 1]) || \
		flags->str[(*i) - 1] == '0') && flags->str[(*i) - 1] != '.')
	{
		flags->zero = 1;
		(*i)++;
	}
	else if (flags->str[(*i)] == '*')
	{
		flags->width = 1;
		flags->asterix_wdt = 1;
		flags->get_width = va_arg(elem, int);
		(*i)++;
	}
	else if (ft_isdigit(flags->str[(*i)]))
	{
		if (flags->width == 0 || flags->asterix_wdt == 1)
			flags->get_width = 0;
		flags->get_width = flags->get_width * 10 + \
			(flags->str[(*i)++] - '0');
		flags->width = 1;
	}
	else if (ft_isdigit(flags->str[(*i)++]) != 1)
		flags->width = 0;
}

void		parse_length(va_list elem, char *str, t_flags *flags)
{
	int		i;

	i = 0;
	(void)elem;
	while (str[i])
	{
		if (str[i] == 'h' || str[i] == 'l' || \
			str[i] == 'j' || str[i] == 'z' || str[i] == 'L')
		{
			if (str[i] == 'h' && str[i + 1] == 'h')
				flags->hh = 1;
			else if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
				flags->h = 1;
			else if (str[i] == 'l' && str[i + 1] != 'l' && str[i - 1] != 'l')
				flags->l = 1;
			else if ((str[i] == 'l' && str[i + 1] == 'l') || str[i] == 'L')
				flags->ll = 1;
			else if (str[i] == 'j')
				flags->j = 1;
			else if (str[i] == 'z')
				flags->z = 1;
		}
		i++;
	}
}
