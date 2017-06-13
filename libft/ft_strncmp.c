/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:32:39 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 16:37:46 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (ch1[i] != '\0' || ch2[i] != '\0'))
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}
