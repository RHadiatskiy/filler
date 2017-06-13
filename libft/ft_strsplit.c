/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 05:09:52 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:46:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if ((s[i] != c && s[i + 1] == c) || s[i + 1] == '\0')
		{
			w++;
			i++;
		}
		else
			i++;
	}
	return (w);
}

static char		**array_mallocate(char **dst, char const *s, char c)
{
	size_t	count;
	size_t	chars;
	size_t	i;

	i = 0;
	count = 0;
	while (s[count] != '\0')
	{
		chars = 0;
		while (s[count] == c && s[count] != '\0')
			count++;
		while (s[count] != c && s[count] != '\0')
		{
			count++;
			chars++;
		}
		if (chars != 0)
		{
			dst[i] = (char *)malloc(sizeof(char) * (chars + 1));
			i++;
		}
	}
	return (dst);
}

static char		**array_put(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	while (s[count] != '\0')
	{
		j = 0;
		while (s[count] == c && s[count] != '\0')
			count++;
		if (s[count] != c && s[count] != '\0')
		{
			while (s[count] != c && s[count] != '\0')
			{
				dst[i][j++] = s[count++];
			}
			dst[i][j] = '\0';
			i++;
		}
	}
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	l;

	if (s && c)
	{
		l = countwords(s, c);
		tab = (char **)malloc(sizeof(char *) * (l + 1));
		if (tab)
		{
			tab = array_mallocate(tab, s, c);
			tab = array_put(tab, s, c);
			tab[l] = 0;
			return (tab);
		}
	}
	return (NULL);
}
