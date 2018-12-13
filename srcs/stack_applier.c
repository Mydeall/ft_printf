/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_applier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:35:08 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/13 14:07:18 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "declaration.h"
#include "format_caller.h"
#include <stdarg.h>

static int	format_caller(va_list ap, char **result, t_stack *stack)
{
	int i;
	int len_arg;

	i = -1;
	while (++i < 5)
	{
		if (ft_strchr(g_call_format[i].format, stack->format))
		{
			if ((len_arg = g_call_format[i].f(ap, stack, result)) == -1)
				return (-1);
			break ;
		}
	}
	if (i == 5)
	{
		if (!(*result = (char*)ft_memalloc(2)))
			return (-1);
		**result = stack->format;
		len_arg = 1;
	}
	return (len_arg);
}

static int	attributs_caller(char **result, t_stack *stack, int len_arg)
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
				if ((len_arg = g_attr_tab[j].f(result, stack, len_arg)) == -1)
					return (-1);
				break ;
			}
	}
	return (len_arg);
}

int			ft_stack_applier(t_stack *stack, va_list ap,\
		char (*buff)[BUFF_SIZE], int *len)
{
	char	*result;
	int		len_arg;

	if ((len_arg = format_caller(ap, &result, stack)) == -1)
		return (-1);
	if (!result)
		return (0);
	if ((len_arg = attributs_caller(&result, stack, len_arg)) == -1)
		return (-1);
	if ((len_arg = ft_width(&result, stack, len_arg)) == -1)
		return (-1);
	concat_buff(buff, result, len_arg, len);
	ft_strdel(&result);
	return (*len);
}
