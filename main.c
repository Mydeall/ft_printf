/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:15:49 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/03 18:21:23 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("return : %i\n", ft_printf("Le test %#-+0 .10s de %.5-.10lld trois %% %0555lllu"));
	else
		printf("return : %i\n", ft_printf(av[1]));
	return (0);
}
