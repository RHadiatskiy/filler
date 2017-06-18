#include "../include/filler.h"

t_coord			*initial_coord_list(void)
{
	t_coord		*initial;

	if (!(initial = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	initial->coord = 0;
	initial->n = 0;
	initial->next = NULL;
	return (initial);
}

t_get_coord		*initial_get_coord_list(void)
{
	t_get_coord		*initial;

	if (!(initial = (t_get_coord *)malloc(sizeof(t_get_coord))))
		return (NULL);
	initial->x = initial_coord_list();
	initial->y = initial_coord_list();
	return (initial);
}

void			coord_list_added(t_coord *list, int coord)
{
	t_coord			*temp;

	if ((temp = (t_coord *)malloc(sizeof(t_coord))))
	{
		if (list->n == 0)
		{
			list->coord = coord;
			list->n = list->n + 1;
		}
		else
		{
			while (list->next)
				list = list->next;
			temp->coord = coord;
			temp->next = NULL;
			list->next = temp;
		}
	}
}

void			print_coord_list(t_get_coord *get_coord)
{
	t_coord		*x_temp;
	t_coord		*y_temp;

	if (get_coord->x)
	{
		x_temp = get_coord->x;
		while (x_temp->next)
		{
			printf("%s%d%s ", GREEN, x_temp->coord, RESET);
			x_temp = x_temp->next;
		}
		printf("%s%d%s\n", GREEN, x_temp->coord, RESET);
	}
	if (get_coord->y)
	{
		y_temp = get_coord->y;
		while (y_temp->next)
		{
			printf("%s%d%s ", RED, y_temp->coord, RESET);
			y_temp = y_temp->next;
		}
		printf("%s%d%s\n", RED, y_temp->coord, RESET);
	}
}