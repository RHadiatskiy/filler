/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:26:15 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/20 15:43:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	b;

	if (!s1 && !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * a + b + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1 != '\0' && a--)
		str[i++] = s1[j++];
	j = 0;
	while (*s2 != '\0' && b--)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
