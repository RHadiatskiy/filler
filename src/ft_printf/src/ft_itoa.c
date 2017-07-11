/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:34:20 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/12 21:54:40 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*base_digit(void)
{
	char	c;
	int		i;
	char	*str;

	c = '0';
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	while (i < 10)
		str[i++] = c++;
	str[i] = '\0';
	return (str);
}

int		ft_nbrlen(long int nbr)
{
	int		i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(intmax_t nbr)
{
	char	*digit;
	char	*it;
	int		len;
	int		minus;

	digit = base_digit();
	len = ft_nbrlen(nbr);
	minus = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		minus = 1;
	}
	it = (char *)malloc(sizeof(char) * len + 1);
	it[len--] = '\0';
	if (nbr == 0)
		it[0] = '0';
	while (len >= 0)
	{
		it[len--] = digit[(nbr % 10)];
		nbr = nbr / 10;
	}
	if (minus == 1)
		it[0] = '-';
	return (it);
}
