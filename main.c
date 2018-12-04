/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:15:49 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 19:08:23 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
//		printf("sentence : %s\n", "Le test %#-+0 .10s de %.5-.10lls trois %% %0555llls");
//		ft_printf("Le test %#-+0 .10s de %.5-.10lls trois %% %0555llls",\
//				   	"bonjour", "hello", "buenos dias");
		printf("sentence : %s\n", "Le test %d de %o trois %% %x");
		ft_printf("Le test %.5hhp de %lo trois %% %llx\n",\
				   	300, 12, 12);
		printf("%#.5hhx", 300);
	}
	else
		printf("return : %i\n", ft_printf(av[1]));
	return (0);
}
