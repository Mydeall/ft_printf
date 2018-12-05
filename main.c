/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:15:49 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/05 18:25:52 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int	main(int ac, char **av)
{
	int a;
	unsigned long long int b;
	
	setlocale(LC_ALL, "");
	a = 140;
	printf("%llu\n", a);
	b = a;
	printf("itoa_b : %s\n", ft_itoa_base(b, "0123456789"));
//	18446744073709551616 -> 2**8*8
//	9223372036854775808 -> 2**(8*8-1)
//	4611686018427387904 -> 2**(8*8-2)
	if (ac != 2)
	{
		ft_printf("perso  : |%hhu|\n", 155);
		printf("offic  : |%hhu|\n", 155);
	}
	else
		printf("return : %i\n", ft_printf(av[1]));
	return (0);
}
