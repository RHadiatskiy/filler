/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:28:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/03/22 19:20:59 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		elem;
	int			ret;

	ret = 0;
	va_start(elem, format);
	ft_print(elem, format, &ret);
	va_end(elem);
	return (ret);
}

void			ft_print(va_list elem, const char *format, int *ret)
{
	int			i;
	t_flags		flags;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			(*ret) += write(1, &format[i], 1);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] != '%' && format[i + 1])
		{
			flags = flags_reset(flags);
			flags.str = memaloc_str(format, &i);
			ft_parse(elem, &flags);
			(*ret) += ft_output_func(elem, flags);
			free(flags.str);
			free(flags.args);
		}
		else if (format[i] != '%')
			(*ret) += (write(1, &format[i++], 1));
		else
			i++;
	}
}

char			*ft_strchrdup(const char *str, int chr)
{
	int		i;
	int		j;
	char	*dup;

	i = 1;
	j = 0;
	while (str[i] && i <= chr && \
		((ft_strlenchr(SPECIFICATE, str[i])) == -1))
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 1;
	dup[j++] = str[0];
	while (str[i] && i <= chr && \
		((ft_strlenchr(SPECIFICATE, str[i])) == -1))
	{
		if ((ft_strlenchr(SPECIFICATE, str[i]) == -1) && \
			(ft_strlenchr(FLAGS, str[i]) == -1) && str[i] != ' ' && \
			!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '*')
			break ;
		dup[j++] = str[i++];
	}
	dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}

char			*memaloc_str(const char *str, int *i)
{
	int			l;
	char		*s;

	l = *i;
	(*i) += 1;
	while ((ft_strlenchr(SPECIFICATE, str[(*i)]) == -1) && str[(*i) + 1])
	{
		if ((str[(*i) + 1] == '%') && \
			(ft_strlenchr(SPECIFICATE, str[(*i) + 2]) != -1))
			break ;
		else if ((ft_strlenchr(SPECIFICATE, str[(*i)]) == -1) && \
			(ft_strlenchr(FLAGS, str[(*i)]) == -1) && str[(*i)] != ' ' && \
			!ft_isdigit(str[(*i)]) && str[(*i)] != '.' && str[(*i)] != '*')
			break ;
		else
			(*i)++;
	}
	if (!(s = ft_strchrdup(&str[l], (*i) + 1)))
		return (NULL);
	(*i)++;
	return (s);
}
