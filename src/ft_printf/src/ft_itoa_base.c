/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:46:03 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 16:46:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		f(uintmax_t value, int base, char *str, int *i)
{
	char			*tmp;

	tmp = "0123456789abcdef";
	if (value >= (uintmax_t)base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char		*ft_itoa_base(intmax_t value, int base)
{
	int				i;
	char			*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (value < 0)
	{
		str[i++] = '-';
		value *= -1;
	}
	f((uintmax_t)value, base, str, &i);
	str[i] = '\0';
	return (str);
}

char		*ft_itoa_base_x(uintmax_t value, int base)
{
	int				i;
	char			*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
