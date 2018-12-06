/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:15:49 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/06 17:50:22 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	18446744073709551616 -> 2**8*8
//	9223372036854775808 -> 2**(8*8-1)
//	4611686018427387904 -> 2**(8*8-2)

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int	main(int ac, char **av)
{
	long double a;
	double b;
	
	setlocale(LC_ALL, "");
	a = 1.12345L;
	b = 1.12345;
	if (ac != 2)
	{
		ft_printf("perso  : |%.17Lf|\n", 1.55L);
		printf("offic  : |%.17Lf|\n", 1.55L);
	}
	else
		printf("return : %i\n", ft_printf(av[1]));
	return (0);
}
