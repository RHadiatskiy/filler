/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 02:14:59 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:45:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checkfront(char const *s)
{
	size_t	a;

	a = 0;
	while (s[a] == '\t' || s[a] == '\n' || s[a] == ' ')
		a++;
	return (a);
}

static size_t	checkback(char const *s)
{
	size_t	b;

	b = ft_strlen(s);
	while (s[b] == '\t' || s[b] == '\n' || s[b] == ' ' || s[b] == '\0')
		b--;
	return (b);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	i;

	if (!s)
		return (NULL);
	a = checkfront(s);
	b = checkback(s);
	if ((s + b) < s)
	{
		str = (char *)malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (b - a) + 2);
	if (str)
	{
		i = 0;
		while (b >= a)
			str[i++] = s[a++];
		str[i] = '\0';
	}
	return (str);
}
