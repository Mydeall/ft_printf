/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:37 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 19:45:08 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hashtag(int arg, char *result, t_stack *stack)
{
	char *tmp;

	if (!(ft_strchr("oxXf", stack->format)))
		return (result);
	tmp = result;
	if (stack->format == 'f' && stack->precision == 0)
		result = ft_strjoin(result, ".");
	else if (stack->format != 'f' && arg != 0)
	{
		if (stack->format == 'o')
			result = ft_strjoin("0", result);
		else if (stack->format == 'x')
			result = ft_strjoin("0x", result);
		else if (stack->format == 'X')
			result = ft_strjoin("0X", result);
	}
	ft_strdel(&tmp);
	return (result);
}

char	*ft_zero(int arg, char *result, t_stack *stack)
{
	char *tmp;

	if (stack->precision == -1)
	{
		tmp = result;
		result = ft_width(result, stack->width, '0', 0);
		ft_strdel(&tmp);
	}
	return (result);
}
