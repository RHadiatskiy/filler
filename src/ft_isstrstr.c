/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:01:58 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/16 17:02:02 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		ft_isstrstr(char *big, char *little)
{
	int		i;
	int		j;
	int		len;

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
