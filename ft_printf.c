/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:06:56 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 18:34:14 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	format_parser(const char * restrict format, t_stack *new)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0; 
	while (ft_strchr("#+-0 .0123456789hlL", format[++i]))
	{
		if (ft_strchr("#+-0 ", format[i]))
		{
			if (!(new->attributs))
				new->attributs = ft_strsub(&format[i], 0, 1);
			else if (!(ft_strchr(new->attributs, format[i])))
			{
				tmp = ft_strsub(&format[i], 0, 1);
				tmp2 = new->attributs;
				if (!(new->attributs = ft_strjoin(new->attributs, tmp)))
					return (-1);
				ft_strdel(&tmp);
				ft_strdel(&tmp);
			}
		}
		else if (format[i] == '.')
		{
			i++;
			new->precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
		}
		else if (format[i] >= '0' && format[i] <= '9')
		{
			new->width= ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
		}
		else if (ft_strchr("hlL", format[i]))
		{
			if (new->modifier)
				ft_strdel(&new->modifier);
			if (format[i + 1] == format[i] && format[i] != 'L')
			{
				if (!(new->modifier = ft_strsub(format, i, 2)))
					return (-1);
				i++;
			}
			else
				if (!(new->modifier = ft_strsub(&format[i], 0, 1)))
					return (-1);
		}
	}
	if (ft_strchr("diouxXcspf", format[i]))
		new->format = format[i];
	i++;
	return (i);
}

int	ft_printf(const char * restrict format, ...)
{
	int 	i;
	int 	j;
	t_stack	*stack;
	va_list	ap;

	if (!(stack = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			j = 0;
			if (format[i + 1] != '%')
			{
				write(1, format, i);
				if ((j = format_parser(&format[i], stack)) == -1)
					return (-1);
				stack_applier(stack, ap);
				node_reset(stack);
			}
			else
			{
				write(1, format, i + 1);
				i += 2;
			}
			format = &format[i + j];
			i = -1;
		}
	}
	write(1, format, ft_strlen(format));
	va_end(ap);
	return (0);
}
