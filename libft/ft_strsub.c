/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:49:48 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:45:12 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;

	l = 0;
	if (s)
	{
		sub = (char *)malloc(sizeof(char) * len + 1);
		if (sub)
		{
			while (len--)
			{
				sub[l] = s[start + l];
				l++;
			}
			sub[l] = '\0';
			return (sub);
		}
	}
	return (NULL);
}
