/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:33:41 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/10 19:05:50 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_format(ULLI arg, t_stack *stack)
{
	char	*result;
	char	*tmp;
	long long int cpy;
	ULLI	ucpy;
	
	if (stack->format == 'd' || stack->format == 'i')
	{
		cpy = int_modifier(arg, stack);
		result = ft_itoa(cpy);
	}
	else
	{
		ucpy = unsigned_modifier(arg, stack);
		result = unsigned_conversion(ucpy, stack);
	}
	result = precision(result, stack);
	if (stack->format == 'p')
	{
		tmp = result;
		result = ft_strjoin("0x", result);
		ft_strdel(&tmp);
	}
	return (result);
}

char	*str_format(char *arg, t_stack *stack)
{
	char	*result;

	result = ft_strdup(arg);
	result = precision(result, stack);
	return (result);
}

int		char_format(int arg, t_stack *stack)
{
	char	*result;
	int		len;

	if (!(result = (char*)ft_memalloc(2)))
		return (-1);
	*result = (char)arg;
	if (!(result = ft_width(result, stack, 1)))
		return (-1);
	len = ft_strlen(result);
	len = arg == 0 ? len + 1 : len;
	write(1, result, len);
	return (len);
}

char	*f_format(long double arg, t_stack *stack)
{
	char 	*result;
	char 	*tmp;
	char	*tmp2;
	int		len;

	arg = f_modifier(arg, stack);
	result = ft_dtoa(arg, stack->precision);
	len = (int)ft_strlen(ft_strchr(result, '.'));
	if (len < stack->precision)
	{
		if (!(tmp = (char*)malloc(stack->precision - len + 2)))
			return (NULL);
		tmp = ft_memset(tmp, '0', stack->precision - len + 1);
		tmp [stack->precision - len + 1] = 0;
		tmp2 = result;
		result = ft_strjoin(result, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (result);
}
