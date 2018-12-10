/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_applier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:35:08 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/10 19:05:37 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "declaration.h"
#include <stdarg.h>

char	*attributs_caller(char *result, t_stack *stack)
{
	int i;
	int j;

	i = -1;
	while (stack->attributs && (stack->attributs)[++i])
	{
		j = -1;
		while (++j < 3)
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
	ULLI	d;
	long double	f;

	if (!(s = (char*)ft_memalloc(2)))
		return (-1);
	if (stack->format == 's')
	{
		s = va_arg(ap, char*);
		if (!(s = str_format(s, stack)) && stack->precision == -1)
			s = ft_strdup("(null)");
	}
	else if (ft_strchr("diouxXpb", stack->format) && stack->format != 0)
	{
		d = va_arg(ap, ULLI);
		if (!(s = int_format(d, stack)))
			return (-1);
	}
	else if (stack->format == 'c')
		return (char_format(va_arg(ap, int), stack));
	else if (stack->format == 'f')
	{
		f = va_arg(ap, long double);
		s = f_format(f, stack);
	}
	else if (stack->format == '%')
		*s = '%';
	else
		*s = stack->format;
	if (!s)
		return (0);
	if (!(s = attributs_caller(s, stack)))
		return (-1);
//	printf("s : |%s|\n", s);
	if (!(s = ft_width(s, stack, ft_strlen(s))))
		return (-1);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
