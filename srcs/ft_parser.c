/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:33:51 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/11 15:28:12 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_format.h"

int	get_attributs(t_stack *new, const char *restrict format, int *i)
{
	char	*tmp;
	char	*tmp2;

	if (!(new->attributs))
		new->attributs = ft_strsub(&format[*i], 0, 1);
	else if (!(ft_strchr(new->attributs, format[*i])))
	{
		tmp = ft_strsub(&format[*i], 0, 1);
		tmp2 = new->attributs;
		if (!(new->attributs = ft_strjoin(new->attributs, tmp)))
			return (-1);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (0);
}

int	get_modifier(t_stack *new, const char *restrict format, int *i)
{
	if (new->modifier)
		ft_strdel(&new->modifier);
	if (format[*i + 1] == format[*i] && format[*i] != 'L')
	{
		if (!(new->modifier = ft_strsub(format, *i, 2)))
			return (-1);
		(*i)++;
	}
	else
	{
		if (!(new->modifier = ft_strsub(&format[*i], 0, 1)))
			return (-1);
	}
	return (0);
}

int	get_precision(t_stack *new, const char *restrict format, int *i)
{
	(*i)++;
	new->precision = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int	get_width(t_stack *new, const char *restrict format, int *i)
{
	new->width = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int	ft_format_parser(const char *restrict format, t_stack *new)
{
	int		i;
	int		j;

	i = 0;
	while (ft_strchr("#+-0 .0123456789hlL", format[++i]) && format[i] != 0)
	{
		j = -1;
		while (++j < 4)
			if (ft_strchr(g_format_tab[j].format, format[i]))
			{
				if (g_format_tab[j].f(new, format, &i) == -1)
					return (-1);
				break ;
			}
	}
	if (format[i] != 0)
	{
		new->format = format[i];
		i++;
	}
	return (i);
}
