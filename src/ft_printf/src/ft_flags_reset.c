/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:52:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/14 16:53:36 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags		flags_reset(t_flags flags)
{
	flags.zero = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.get_width = 0;
	flags.get_precision = 0;
	flags.asterix_wdt = 0;
	flags.asterix_pre = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.j = 0;
	flags.z = 0;
	flags.specificate = 0;
	flags.str = NULL;
	flags.args = NULL;
	return (flags);
}
