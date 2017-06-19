#include "../include/filler.h"

t_get_coord		*initial_get_coord_list(void)
{
	t_get_coord		*initial;

	if (!(initial = (t_get_coord *)malloc(sizeof(t_get_coord))))
		return (NULL);
	initial->x = 0;
	initial->y = 0;
	initial->n = 0;
	initial->next = NULL;
	return (initial);
}

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
			printf("%jd %jd \tn :%d\n", get_coord->x, get_coord->y, get_coord->n);
			get_coord = get_coord->next;
		}
	}
}