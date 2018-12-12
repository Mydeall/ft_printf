/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:06:25 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/12 15:00:15 by ccepre           ###   ########.fr       */
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

/*
void	print_lst(t_stack *stack)
{
	t_stack *current;
	int count;

	count = 1;
	current = stack;
	while (current)
	{
		ft_putstr("Node nb : ");
		ft_putnbr(count);
		ft_putstr("\n");
		print_node(current);
		count++;
		current = current->next;
	}
}

void		lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack *current;

	if (!(lst))
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	current->next->next = NULL;
}
*/
void		node_reset(t_stack *lst)
{
	if (lst->attributs)
		ft_strdel(&lst->attributs);
	lst->attributs = NULL;
	if (lst->modifier)
		ft_strdel(&lst->modifier);
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
	free(lst);
}
