/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:15:49 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/10 15:51:43 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	18446744073709551616 -> 2**8*8
//	9223372036854775808 -> 2**(8*8-1)
//	4611686018427387904 -> 2**(8*8-2)

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

char                *ft_dtoa_v2(long double n, int precision);

int test(int a, int b, int c, int d, int e)
{
	return (0);
}

int	main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	if (ac != 2)
	{
		ft_printf("{%03.2d}\n", 0);
		printf("OK\n");
		ft_printf("{%03.2s}\n", "test");
		//ft_printf("{%03.2d}\n", 0);
	}
	else
		printf("return : %i\n", ft_printf(av[1]));
	return (0);
}
