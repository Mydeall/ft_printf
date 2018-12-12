/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:37 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/12 14:23:05 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hashtag(char **result, t_stack *stack, int len_arg)
{
	char *tmp;
	int verif;

	if (!(ft_strchr("oxXfb", stack->format)))
		return (len_arg);
	tmp = *result;
	if (stack->format == 'f' && stack->precision == 0)
		*result = ft_strjoin(*result, ".");
	else if (stack->format != 'f')
	{
		verif = 0;
		while ((*result)[verif] == '0')
			verif++;
		if (verif == len_arg &&	!(stack->precision == 0 && len_arg == 0 &&\
					stack->format == 'o'))
			return (len_arg);
		if (stack->format == 'o' || stack->format == 'b')
		{
			if (stack->format == 'o')
				*result = ft_strjoin("0", *result);
			else if (stack->format == 'b')
				*result = ft_strjoin("b", *result);
			len_arg += 1;
		}
		else if (stack->format == 'x' || stack->format == 'X')
		{
			if (stack->format == 'x')
				*result = ft_strjoin("0x", *result);
			else if (stack->format == 'X')
				*result = ft_strjoin("0X", *result);
			len_arg += 2;
		}
	}
	if (tmp != *result)
		ft_strdel(&tmp);
	return (len_arg);
}

int	ft_plus(char **result, t_stack *stack, int len_arg)
{
	char *tmp;

	if (ft_strchr("dif", stack->format))
	{
		if (ft_atoi(*result) >= 0) // WARNING AT ATOI WHEN DOUBLE (SEPARATE ?)
		{
			tmp = *result;
			*result = ft_strjoin("+", *result);
			len_arg += 1;
			ft_strdel(&tmp);
		}
	}
	return (len_arg);
}

int	ft_space(char **result, t_stack *stack, int len_arg)
{
	char *tmp;

	if (ft_strchr("dif", stack->format) && !ft_strchr(stack->attributs, '+'))
	{
		if (ft_atoi(*result) >= 0) // IDEM
		{
			tmp = *result;
			*result = ft_strjoin(" ", *result);
			len_arg += 1;
			ft_strdel(&tmp);
		}
	}
	return (len_arg);	
}
