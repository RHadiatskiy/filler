/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:50:42 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:08:51 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (src[i] == ch)
			return (src + i);
		i++;
	}
	return (0);
}
