/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_u_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:57:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/19 20:57:45 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			len_u_prec(wchar_t *s, int prec)
{
	int		i;
	int		sum;
	int		n;

	n = 0;
	sum = prec;
	i = 0;
	while (s[i] && prec > i)
	{
		if (ucodelen(s[i]) <= sum)
		{
			sum -= ucodelen(s[i]);
			n += ucodelen(s[i]);
		}
		else if (sum > 0)
			break ;
		i++;
	}
	return (n);
}
