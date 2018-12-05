/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_applier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:35:08 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/05 18:04:20 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "declaration.h"
#include <stdarg.h>

char	*ft_width(char *result, int width, char c, int side)
{
	char	*str;
	char	*tmp;

	if ((int)ft_strlen(result) < width)
	{
		if (!(str = (char*)ft_memalloc(width - ft_strlen(result) + 1)))
			return (NULL);
		ft_memset(str, c, width - ft_strlen(result));
		tmp = result;
		if (side == 0)
			if (!(result = ft_strjoin(str, result)))
				return (NULL);
		if (side == 1)
			if (!(result = ft_strjoin(result, str)))
				return (NULL);
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (result);
}

char	*attributs_caller(char *result, t_stack *stack)
{
	int i;
	int j;

	i = -1;
	while (stack->attributs && (stack->attributs)[++i])
	{
		j = -1;
		while (++j < 5)
			if (g_attr_tab[j].attr == (stack->attributs)[i])
			{
				if (!(result = g_attr_tab[j].f(result, stack)))
					return (NULL);
				break;
			}
	}
	return (result);
}

int		stack_applier(t_stack *stack, va_list ap)
{
	char	*s;
	char	c;
	ULLI	d;
//	double	f;

	if (!(s = (char*)ft_memalloc(2)))
		return (-1);
	*s = NULL;
	if (stack->format == 's')
	{
		s = va_arg(ap, char*);
		if (!(s = str_format(s, stack)))
			return (-1);
	}
	else if (ft_strchr("diouxXp", stack->format))
	{
		d = va_arg(ap, ULLI);
		if (!(s = int_format(d, stack)))
			return (-1);
	}
	else if (stack->format == 'c')
		*s = va_arg(ap, int);
/*	else if (stack->format == 'f')
		f = va_arg(ap, double);
*/	
	if (!(s = attributs_caller(s, stack)))
		return (-1);
	if (!(s = ft_width(s, stack->width, ' ', 0)))
		return (-1);
	write(1, s, ft_strlen(s));
	return (0);
}
