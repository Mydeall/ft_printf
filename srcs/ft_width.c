/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:42 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/07 16:45:46 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(char *result, t_stack *stack)
{
	int i;
	char *str;
	char *tmp;
	char *sub;

	if (stack->attributs && stack->precision == -1 && \
			!ft_strchr(stack->attributs, '-'))
	{
		i = 0;
		while (result[i] < '1' && result[++i] > '9')
			i++;
		if (!(str = (char*)ft_memalloc(stack->width - ft_strlen(result) + 1))\
				|| !(sub = ft_strsub(result, 0, i)))
			return (NULL);
		ft_memset(str, '0', stack->width - ft_strlen(result));
		tmp = result;
		result = &result[i];
		result = ft_strjoin(str, result);
		ft_strdel(&tmp);
		tmp = result;
		result = ft_strjoin(sub, result);
		ft_strdel(&tmp);
		ft_strdel(&sub);
	}
	return (result);
}
/*
char	*ft_minus(char *result, t_stack *stack)
{
	
}
*/
char	*ft_width(char *result, t_stack *stack)
{
	char	*str;
	char	*tmp;

	if ((int)ft_strlen(result) < stack->width)
	{
		if (stack->attributs && ft_strchr(stack->attributs, '0'))
			result = ft_zero(result, stack);
		if (!(str = (char*)ft_memalloc(stack->width - ft_strlen(result) + 1)))
			return (NULL);
		ft_memset(str, ' ', stack->width - ft_strlen(result));
		tmp = result;
		if (stack->attributs &&  ft_strchr(stack->attributs, '-'))
			result = ft_strjoin(result, str);
		else
			result = ft_strjoin(str, result);
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (result);
}
