/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:49:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/22 11:54:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_output_func(va_list elem, t_flags flags)
{
	int		n;

	n = ft_strlenchr(SPECIFICATE, flags.str[ft_strlen(flags.str) - 1]);
	if (n == -1)
		n = 17;
	g_func[0] = ft_s_low;
	g_func[1] = ft_s_high;
	g_func[2] = ft_p;
	g_func[3] = ft_d_low;
	g_func[4] = ft_d_high;
	g_func[5] = ft_i;
	g_func[6] = ft_o_low;
	g_func[7] = ft_o_high;
	g_func[8] = ft_u_low;
	g_func[9] = ft_u_high;
	g_func[10] = ft_x_low;
	g_func[11] = ft_x_high;
	g_func[12] = ft_c_low;
	g_func[13] = ft_c_high;
	g_func[14] = ft_fl_low;
	g_func[15] = ft_fl_high;
	g_func[16] = ft_percent;
	g_func[17] = ft_none;
	return ((*g_func[n])(elem, flags));
}
