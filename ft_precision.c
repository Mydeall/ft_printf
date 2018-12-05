/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:26:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/05 15:16:37 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*int_precision(char *result, int precision)
{
	char	*str;
	char	*tmp;

	if ((int)ft_strlen(result) < precision)
	{
		if (!(str = (char*)ft_memalloc(precision - ft_strlen(result) + 1)))
			return (NULL);
		ft_memset(str, '0', precision - ft_strlen(result));
		tmp = result;
		if (!(result = ft_strjoin(str, result)))
			return (NULL);
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (result);
}

static char	*str_precision(char *result, int precision)
{
	char	*tmp;

	if (result && precision != -1 && (int)ft_strlen(result) > precision)
	{
		tmp = result;
		result = ft_strsub(result, 0, precision);
		ft_strdel(&tmp);
	}
	return (result);
}

char	*precision(char	*result, t_stack *stack)
{
	if (ft_strchr("diouxXp", stack->format))
		return (int_precision(result, stack->precision));
	else if (stack->format == 's')
	{
		return (str_precision(result, stack->precision));
	}
	return (result);
}
