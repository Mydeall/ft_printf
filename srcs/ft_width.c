/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:42 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/10 19:01:18 by ccepre           ###   ########.fr       */
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

static int	ft_zero(char **result, t_stack *stack, int len)
{
	char *strz;
	char *tmp;

	if (stack->attributs && (stack->precision == -1 || 
		ft_strchr("cs", stack->format)) && !ft_strchr(stack->attributs, '-'))
	{
		if (!(strz = (char*)ft_memalloc(stack->width - len + 1)))
			return (len);
		ft_memset(strz, '0', stack->width - len);
		tmp = *result;
		if (ft_strchr("diouxXpfb", stack->format))
			if (!(strz = digit_zero(result, strz)))
				return (len);
		if (!(*result = ft_strjoin(strz, *result)))
			return (len);
		ft_strdel(&tmp);
		len += stack->width - len;
	}
	return (len);
}

char	*ft_width(char *result, t_stack *stack, int len)
{
	char	*str;
	char	*tmp;

	if ((int)ft_strlen(result) < stack->width)
	{
		if (stack->attributs && ft_strchr(stack->attributs, '0'))
			len = ft_zero(&result, stack, len);
		if (!(str = (char*)ft_memalloc(stack->width - len + 1)))
			return (NULL);
		ft_memset(str, ' ', stack->width - len);
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
