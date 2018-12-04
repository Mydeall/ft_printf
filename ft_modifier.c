/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:13:55 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 18:49:29 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// particulier pour f
// ATTENTION c accepte les modifier (gere comme un int ?)
// Ne pas prendre s ni p

int	int_modifier(int arg, t_stack *stack)
{
	if (!(stack->modifier) || stack->format == 'p')
		return (arg);
	else if (ft_strcmp("hh", stack->modifier) == 0)
		return ((char)arg);
	else if (ft_strcmp("h", stack->modifier) == 0)
		return ((short int)arg);
	else if (ft_strcmp("l", stack->modifier) == 0)
		return ((long int)arg);
	else if (ft_strcmp("ll", stack->modifier) == 0)
		return ((long long int)arg);
	return (arg);
}
