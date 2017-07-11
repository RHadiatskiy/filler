/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_addition_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:11:49 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/06 14:12:12 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualize.h"

char			uppersymb(char symbol)
{
	if (symbol == 'x' || symbol == 'o')
		return (symbol - 32);
	else
		return (symbol);
}

int				ft_isstrstr(char *big, char *little)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	while (big[i])
	{
		len = 0;
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j])
			{
				i++;
				j++;
				len++;
			}
			if (len == ft_strlen(little))
				return (1);
		}
		else
			i++;
	}
	return (0);
}
