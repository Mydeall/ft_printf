/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:33:41 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 18:09:23 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_format(int arg, t_stack *stack)
{
	char	*result;
	char	*tmp;
	int		i;
	
	arg = int_modifier(arg, stack);
	result = int_conversion(arg, stack);
	result = precision(result, stack);
	if (stack->format == 'p')
	{
		tmp = result;
		result = ft_strjoin("0x", result);
		ft_strdel(&tmp);
	}
	return (result);
}
