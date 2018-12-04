/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_applier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:35:08 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 19:56:20 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "declaration.h"
#include <stdarg.h>

char	*ft_width(char *result, int width, char c, int side)
{
	char	*str;
	char	*tmp;

	if (ft_strlen(result) < width)
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
		return (result);
	}
	return (result);
}

char	*attributs_caller(int arg, char *result, t_stack *stack)
{
	int i;
	int j;

	i = -1;
	while ((stack->attributs)[++i])
	{
		j = -1;
		while (++j < 5)
			if (g_attr_tab[j].attr == (stack->attributs)[i])
			{
				if (!(result = g_attr_tab[j].f(arg, result, stack)))
					return (NULL);
				break;
			}
	}
	return (result);
}

int		stack_applier(t_stack *stack, va_list ap)
{
	char			*s;
	char			c;
	int				d;
	unsigned int	u;
	double			f;

	if (stack->format == 's')
		s = va_arg(ap, char*);
	else if (ft_strchr("dioxXp", stack->format))
	{
		d = va_arg(ap, int);
		if (!(s = int_format(d, stack) || \
				!(s = attributs_caller(d, s, stack))))
			return (-1);
	}
/*	else if (stack->format == 'u')
		u = va_arg(ap, unsigned int);
	else if (stack->format == 'c')
		c = va_arg(ap, int);
	else if (stack->format == 'f')
		f = va_arg(ap, double);
*/	
	write(1, s, ft_strlen(s));
	return (0);
}
