/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:37 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/10 19:00:37 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hashtag(char *result, t_stack *stack)
{
	char *tmp;
	int verif;

	if (!(ft_strchr("oxXfb", stack->format)))
		return (result);
	tmp = result;
	if (stack->format == 'f' && stack->precision == 0)
		result = ft_strjoin(result, ".");
	else if (stack->format != 'f')
	{
		verif = 0;
		while (result[verif] == '0')
			verif++;
		if (verif == (int)ft_strlen(result) &&\
				!(stack->precision == 0 && (int)ft_strlen(result) == 0 &&\
				   	stack->format == 'o'))
			return (result);
		if (stack->format == 'o')
			result = ft_strjoin("0", result);
		else if (stack->format == 'x')
			result = ft_strjoin("0x", result);
		else if (stack->format == 'X')
			result = ft_strjoin("0X", result);
		else if (stack->format == 'b')
			result = ft_strjoin("b", result);
	}
	if (tmp != result)
		ft_strdel(&tmp);
	return (result);
}

char	*ft_plus(char *result, t_stack *stack)
{
	char *tmp;

	if (ft_strchr("dif", stack->format))
	{
		if (ft_atoi(result) >= 0) // WARNING AT ATOI WHEN DOUBLE (SEPARATE ?)
		{
			tmp = result;
			result = ft_strjoin("+", result);
			ft_strdel(&tmp);
		}
	}
	return (result);
}

char	*ft_space(char *result, t_stack *stack)
{
	char *tmp;

	if (ft_strchr("dif", stack->format) && !ft_strchr(stack->attributs, '+'))
	{
		if (ft_atoi(result) >= 0) // IDEM
		{
			tmp = result;
			result = ft_strjoin(" ", result);
			ft_strdel(&tmp);
		}
	}
	return (result);	
}
