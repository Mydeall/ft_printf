/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:19:16 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 17:28:33 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_conversion(int arg, t_stack *stack)
{
	if (stack->format == 'o')
		return (ft_itoa_base(arg, "012345678"));
	else if (stack->format == 'X')
		return (ft_itoa_base(arg, "0123456789ABCDEF"));
	else if (stack->format == 'x' || stack->format == 'p')
		return (ft_itoa_base(arg, "0123456789abcdef"));
	return (ft_itoa(arg));
}
