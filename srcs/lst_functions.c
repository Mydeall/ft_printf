/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:04:39 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/13 14:37:45 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_node(t_stack *current)
{
	ft_putendl("{");
	ft_putstr("Attributs : |");
	if (current->attributs)
		ft_putstr(current->attributs);
	ft_putstr("|\nWidth : ");
	ft_putnbr(current->width);
	ft_putstr("\nPrecision : |");
	ft_putnbr(current->precision);
	ft_putstr("|\nModifier : |");
	if (current->modifier)
		ft_putstr(current->modifier);
	ft_putstr("|\nformat : |");
	ft_putstr(&current->format);
	ft_putendl("|\n}");
}

void	node_reset(t_stack *lst)
{
	lst->attributs = NULL;
	lst->modifier = NULL;
	lst->width = 0;
	lst->precision = -1;
	lst->format = 0;
}

void	free_node(t_stack *lst)
{
	if (lst->attributs)
		ft_strdel(&lst->attributs);
	if (lst->modifier)
		ft_strdel(&lst->modifier);
}
