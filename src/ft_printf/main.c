/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:37:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/21 13:40:26 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <locale.h>

int			main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
//  ft_printf("ololo%s%%ss% 4%%%%5.2sololo\n", "...", "42");
//  printf("ololo%s%%ss% 4%%%%5.2sololo\n", "...", "42");
ft_printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
//	printf("------------------------------\n");
	 printf("\nret = %d\n", printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200));
	 printf("\nret ft = %d\n", ft_printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200));
	// printf("\nret = %d\n", printf("%hhO, %hhO", 0, USHRT_MAX));
	// printf("\nret ft = %d\n", ft_printf("%hhO, %hhO", 0, USHRT_MAX));
	// printf("\nret = %d\n", printf("{%-15Z}", 123));
	// printf("\nret ft = %d\n", ft_printf("{%-15Z}", 123));
	// printf("\nret = %d\n", printf("%O", LONG_MIN));
	// printf("\nret ft = %d\n", ft_printf("%O", LONG_MIN));
	// printf("\nret = %d\n", printf("%2c", 0));
	// printf("\nret ft = %d\n", ft_printf("%2c", 0));
	// printf("\nret = %d\n", printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));
	// printf("\nret ft = %d\n", ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));
	// printf("\nret = %d\n", printf("%C", L'ÁM-^L´'));
	// printf("\nret ft = %d\n", ft_printf("%C", L'ÁM-^L´'));
	// printf("\nret = %d\n", printf("{%*d}", -5, 42));
	// printf("\nret ft = %d\n", ft_printf("{%*d}", -5, 42));
	// printf("------------------------------------------\n");
	// printf("\nret = %d\n", printf("{%60S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	// printf("\nret ft = %d\n", ft_printf("{%60S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	// printf("------------------------------------------\n");
	// printf("\nret = %d\n", printf("{%f}{%F}", 1.42, 1.42));
	// printf("\nret ft = %d\n", ft_printf("{%f}{%F}", 1.42, 1.42));
	// printf("------------------------------------------\n");
	// printf("\nret = %d\n", printf("@main_ftprintf: %####0000 33..1..#0.0d\n", 256));
	// printf("\nret ft = %d\n", ft_printf("@main_ftprintf: %####0000 33..1..#0.0d\n", 256));
	// printf("------------------------------------------\n");
	// printf("\nret = %d\n", printf("%*.*d", 0, 3, 0));
	// printf("------------------------------------------\n");
	// printf("\nret ft = %d\n", ft_printf("%*.*d", 0, 3, 0));
	// printf("------------------------------------------\n");
	// printf("\nret = %d\n", printf("{%.*d}", 5, 42));
	// printf("------------------------------------------\n");
	// printf("\nret ft = %d\n", ft_printf("{%.*d}", 5, 42));
	// printf("------------------------------------------\n");

	return (0);
}
