/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:23:40 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:32:59 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	n = 0;
	if (size >= d)
	{
		while ((src[n] != '\0') && (d < size - 1))
		{
			dst[d++] = src[n++];
		}
		dst[d] = '\0';
		return ((s - n) + d);
	}
	return (s + size);
}
