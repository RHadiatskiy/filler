/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:46:08 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:27:00 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	i = 0;
	while (ch1[i] != '\0')
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (ch1[i] - ch2[i]);
}
