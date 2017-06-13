/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:38:43 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/29 15:05:23 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && del)
	{
		while ((*alst) != NULL)
		{
			tmp = (*alst);
			(*alst) = (*alst)->next;
			del(tmp, tmp->content_size);
		}
		free(*alst);
		*alst = NULL;
	}
}
