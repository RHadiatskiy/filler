/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:41:12 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:38:28 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	char	*src;
	size_t	i;

	i = 0;
	if (s && f)
	{
		src = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		dst = src;
		if (src)
		{
			while (s[i])
			{
				src[i] = f(i, s[i]);
				i++;
			}
			src[i] = '\0';
			return (dst);
		}
	}
	return (0);
}
