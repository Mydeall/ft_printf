/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:26:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/12 17:51:23 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*int_precision(char *result, int precision)
{
	char	*str;

	if (result && (int)ft_strlen(result) < precision)
	{
		if (!(str = (char*)ft_memalloc(precision - ft_strlen(result) + 1)))
			return (NULL);
		ft_memset(str, '0', precision - ft_strlen(result));
		if (!(result = ft_strjoin(str, result)))
			return (NULL);
		ft_strdel(&str);
	}
	else if (result && precision == 0 && !(ft_strcmp(result, "0")))
		result = ft_strnew(1);
	return (result);
}

char *double_precision(char *result, int precision, int len)
{
	char *strz;
	char *tmp;
	if (precision == 0)
	{
		tmp = result;
		result = ft_strsub(result, 0, ft_strlen(result) - (len + 1));
		ft_strdel(&tmp);
		return (result);
	}
	if (!(strz = (char*)malloc(precision - len + 1)))
		return (NULL);
	strz = ft_memset(strz, '0', precision - len);
	strz[precision - len] = 0;
	tmp = result;
	result = ft_strjoin(result, strz);
	ft_strdel(&strz);
	ft_strdel(&tmp);
	return (result);
}

char	*precision(char	*result, t_stack *stack)
{
	char *tmp;
	char *sub;
	int i;

	if (result && ft_strchr("diouxXpb", stack->format))
	{
		i = 0;
		if (ft_strcmp(result, "0"))
			while (result && result[i] && ft_strchr("0xXb+- ", result[i]))
				i++;
		if (!(sub = ft_strsub(result, 0, i)))
			return (NULL);
		tmp = result;
		result = int_precision(&result[i], stack->precision);
		if (tmp != result)
			ft_strdel(&tmp);
		tmp = result;
		result = ft_strjoin(sub, result);
		if (tmp != result)
			ft_strdel(&tmp);
		ft_strdel(&sub);
		return (result);
	}
	else if (stack->format == 's')
		return (str_precision(result, stack->precision));
	return (result);
}
