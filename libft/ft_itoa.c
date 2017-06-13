/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:09:57 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 14:53:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	int				negative;

	negative = 1;
	if (n < 0)
		negative = -1;
	return (negative);
}

static int	count_nb(long int nb)
{
	int				count;

	count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long int		temp;
	char			*str;
	int				negative;
	unsigned int	len;

	negative = is_negative(n);
	temp = (long int)n;
	len = count_nb(temp);
	str = (char *)malloc(sizeof(char) * len + 1);
	temp = temp * negative;
	if (str)
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = temp % 10 + '0';
			temp = temp / 10;
		}
		if (negative == -1)
			str[0] = '-';
		return (str);
	}
	return (NULL);
}
