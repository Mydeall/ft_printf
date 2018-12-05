/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:33:41 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/05 18:25:08 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_format(ULLI arg, t_stack *stack)
{
	char	*result;
	char	*tmp;
	long long int cpy;
	ULLI	ucpy;
	
	if (stack->format == 'd' || stack->format == 'i')
	{
		cpy = int_modifier(arg, stack);
		result = ft_itoa(cpy);
	}
	else
	{
		ucpy = unsigned_modifier(arg, stack);
		result = unsigned_conversion(ucpy, stack);
	}
	result = precision(result, stack);
	if (stack->format == 'p')
	{
		tmp = result;
		result = ft_strjoin("0x", result);
		ft_strdel(&tmp);
	}
	return (result);
}

char	*str_format(char *arg, t_stack *stack)
{
	char	*result;

	result = ft_strdup(arg);
	result = precision(result, stack);
	return (result);
}
