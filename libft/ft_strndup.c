/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:34:13 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:41:08 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	j = 0;
	while (str[i] != '\0' && n--)
		i++;
	string = (char *)malloc(sizeof(*str) * i + 1);
	if (string == NULL)
		return (NULL);
	while (i--)
	{
		string[i] = str[i];
		j++;
	}
	string[j] = '\0';
	return (string);
}
