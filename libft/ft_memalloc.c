/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:14:52 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:06:48 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (char *)malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
