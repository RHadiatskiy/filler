/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:27:43 by rhadiats          #+#    #+#             */
/*   Updated: 2016/12/28 21:52:52 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*dst;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	dst = tmp;
	while (lst->next)
	{
		tmp->next = f(lst->next);
		if (tmp->next == NULL)
			return (0);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (dst);
}
