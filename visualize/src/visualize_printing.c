/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:12:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/07/11 19:12:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualize.h"

void			print_map(char **map, t_player *player)
{
	size_t		i;
	size_t		j;
	char		filler;

	i = 0;
	filler = player->first == 1 ? 'O' : 'X';
	ft_printf("\n\033[6;0H");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (uppersymb(map[i][j]) == filler)
				ft_printf("%s%c%s", GREEN, map[i][j++], RESET);
			else if (map[i][j] == '.')
				ft_printf("%s%c%s", WHITE, map[i][j++], RESET);
			else
				ft_printf("%s%c%s", RED, map[i][j++], RESET);
		}
		ft_printf("\n");
		i++;
	}
}

void			print_result(t_player *player)
{
	ft_printf("\n%sFILLER :\t%jd%s\n%sENEMY :\t\t%jd%s\n\n", GREEN, \
		player->res_filler, RESET, RED, player->res_enemy, RESET);
	if (player->res_filler > player->res_enemy)
		ft_printf("\n%sWINNER IS %s!%s\n\n", GREEN, "FILLER", RESET);
	else
		ft_printf("\n%sWINNER IS %s!%s\n\n", RED, "ENEMY", RESET);
}
