/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:41:47 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/29 19:41:48 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void			coord_list_added(t_get_coord *list, size_t x, size_t y)
{
	t_get_coord		*temp;

	if (list->n == 0 && list->next == NULL)
	{
		list->x = x;
		list->y = y;
		list->n++;
	}
	else
	{
		if ((temp = (t_get_coord *)malloc(sizeof(t_get_coord))))
		{
			while (list->next)
				list = list->next;
			temp->x = x;
			temp->y = y;
			temp->n = list->n + 1;
			temp->next = NULL;
			list->next = temp;
		}
	}
}

void			print_coord_list(t_get_coord *get_coord)
{
	if (get_coord)
	{
		while (get_coord->next)
		{
			dprintf(2, "%s%jd %jd%s \tn :%d\n", GREEN, get_coord->x, get_coord->y, RESET, get_coord->n);
			get_coord = get_coord->next;
		}
		dprintf(2, "%s%jd %jd%s \tn :%d\n", GREEN, get_coord->x, get_coord->y, RESET, get_coord->n);
	}
}
