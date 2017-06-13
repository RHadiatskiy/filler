/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:13:01 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 14:48:39 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	size_t	num;
	size_t	minus;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i++;
		minus = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * minus);
}
