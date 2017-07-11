/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:57:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:36:56 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char				*check_max(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s[i] == '-' && s[i + 1] == '-' && ft_isdigit(s[i + 2]))
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s))))
			return (NULL);
		i++;
		while (s[i])
			str[j++] = s[i++];
		str[j] = '\0';
	}
	else
		return (s);
	return (str);
}

intmax_t			check_lenght(t_flags flags, intmax_t d)
{
	if (flags.ll == 1)
		return ((long long)d);
	else if (flags.z == 1)
		return ((size_t)d);
	else if (flags.j == 1)
		return (d);
	else if (flags.l == 1)
		return ((long)d);
	else if (flags.h == 1)
		return ((short)d);
	else if (flags.hh == 1)
		return ((char)d);
	else
		return ((int)d);
}

char				*fillsmb(char c, int n)
{
	char		*s;
	int			i;

	i = 0;
	if (n <= 0)
		n = 0;
	if (!(s = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (n-- > 0)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}

char				*spec_d_modify(int width, int prec, t_flags flags, int m)
{
	char		*res_d;
	char		*s_zero;
	char		*s_space;

	flags.m = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.zero == 1 && flags.precision == 0 && flags.minus == 0)
		s_zero = (flags.plus == 1 || m == 1 || flags.space == 1) ? \
		fillsmb('0', width - ft_strlen(flags.args) - 1) : \
		fillsmb('0', width - ft_strlen(flags.args));
	else
		s_zero = fillsmb('0', prec - ft_strlen(flags.args));
	s_space = (m == 0 && flags.space == 0 && flags.plus == 0) ? \
		(fillsmb(' ', width - flags.m)) : (fillsmb(' ', (width - flags.m - 1)));
	res_d = ft_strjoin(s_zero, flags.args);
	if (flags.plus == 1 && m != 1)
		res_d = ft_strjoin("+", res_d);
	if (m == 1)
		res_d = ft_strjoin("-", res_d);
	if (flags.space == 1 && m == 0 && flags.plus == 0)
		res_d = ft_strjoin(" ", res_d);
	if (flags.precision == 1 || flags.zero == 0 || flags.minus == 1)
		flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}

int					ft_d_low(va_list elem, t_flags flags)
{
	int			width;
	int			prec;
	long long	r;
	int			minus;

	minus = 0;
	r = check_lenght(flags, va_arg(elem, intmax_t));
	if (r < 0)
	{
		r *= -1;
		minus = 1;
	}
	flags.args = ft_itoa_base(r, 10);
	prec = flags.get_precision;
	width = flags.get_width;
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_d_modify(width, prec, flags, minus);
	return (ft_printing(check_max(flags.args)));
}
