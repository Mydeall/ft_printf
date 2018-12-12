/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:42 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/12 16:06:06 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*digit_zero(char **result, char *strz)
{
	char *tmp;
	char *sub;
	int i;

	i = 0;
	while ((ft_strchr("0xXb+- ", (*result)[i])) && (*result)[i] != 0)
		i++;
	if (!(sub = ft_strsub(*result, 0, i)))
		return (NULL);
	*result = &(*result)[i];
	tmp = strz;
	strz = ft_strjoin(sub, strz);
	ft_strdel(&tmp);
	ft_strdel(&sub);
	return (strz);
}

static int	ft_zero(char **result, t_stack *stack, int len_arg)
{
	char *strz;
	char *tmp;

	if (!(strz = (char*)ft_memalloc(stack->width - len_arg + 1)))
		return (-1);
	ft_memset(strz, '0', stack->width - len_arg);
	tmp = *result;
	if (ft_strchr("diouxXpfb", stack->format))
		if (!(strz = digit_zero(result, strz)))
			return (-1);
	if (!(*result = ft_strjoin(strz, *result)))
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&strz);
	len_arg += stack->width - len_arg;
	return (len_arg);
}

int		ft_width(char **result, t_stack *stack, int len_arg)
{
	char	*str;
	char	*tmp;

	if (len_arg < stack->width)
	{
		if (stack->attributs && ft_strchr(stack->attributs, '0') &&\
				(stack->precision == -1 || ft_strchr("cs", stack->format))\
				&& !ft_strchr(stack->attributs, '-'))
			return(ft_zero(result, stack, len_arg));
		if (!(str = (char*)ft_memalloc(stack->width - len_arg + 1)))
			return (-1);
		ft_memset(str, ' ', stack->width - len_arg);
		tmp = *result;
		if (stack->attributs &&  ft_strchr(stack->attributs, '-'))
			*result = ft_strjoin(*result, str);
		else
			*result = ft_strjoin(str, *result);
		if (!(*result))
			return (-1);
		len_arg += stack->width - len_arg;
		ft_strdel(&str);
		if (tmp != *result)
			ft_strdel(&tmp);
	}
	return (len_arg);
}
