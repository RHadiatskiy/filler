/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:45:55 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:44:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	if (!*little)
		return ((char *)big);
	return (0);
}
