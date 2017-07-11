/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:43:45 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 14:43:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_c_high(va_list elem, t_flags flags)
{
	wchar_t		c;

	(void)flags;
	c = (wchar_t)va_arg(elem, wchar_t);
	return (choose_mask(c));
}
