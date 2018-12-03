/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:06:56 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/03 18:19:53 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	format_parser(const char * restrict format, t_stack **stack)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	t_stack	*new;

	if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (1);
	new->precision = -1;
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
					return (1);
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
					return (1);
				i++;
			}
			else
				if (!(new->modifier = ft_strsub(&format[i], 0, 1)))
					return (1);
		}
	}
	if (ft_strchr("diouxXcspf", format[i]))
		new->format = format[i];
	lst_add_back(stack, new);
	return (0);
}

int	ft_printf(const char * restrict format, ...)
{
	int 	nb_arg;
	int 	i;
	t_stack	**stack;

	if (!(stack = (t_stack**)ft_memalloc(sizeof(t_stack*))))
		return (0);
	nb_arg = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				if (format_parser(&format[i], stack))
					return (-1);
				nb_arg++;
			}
			else
				i++;
		}
	}
	if (*stack)
		print_lst(*stack);
	return (nb_arg);
}
