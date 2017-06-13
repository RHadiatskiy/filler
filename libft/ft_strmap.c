/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:03:33 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:37:20 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*src;
	char	*dst;

	if (s && f)
	{
		src = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		dst = src;
		if (src)
		{
			while (*s)
			{
				*src++ = f(*s++);
			}
			*src = '\0';
			return (dst);
		}
	}
	return (0);
}
