/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_applier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:35:08 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/19 17:59:13 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
/*
t_call_format call_format[] =
{
	{"diouxXpb", &int_format},
	{"s", &str_format},
	{"c", &char_format},
	{"f", &double_format},
	{"%", &percent_format}
};

t_attributs call_attr[] =
{
	{'#', &ft_hashtag},
	{'+', &ft_plus},
	{' ', &ft_space},
};
*/
static int		format_caller(t_struct_tab struct_tab, va_list ap,\
		char **result, t_stack *stack)
{
	int				i;
	int				len_arg;
//	t_call_format	*call_format;

	i = -1;
	len_arg = 0;
//	call_format = make_call_format();
	while (++i < 5)
	{
		if (stack->format && ft_strchr(struct_tab.call_format[i].format,\
				   	stack->format))
		{
			printf("ok format callr\n");
			printf("%d\n", i);
			printf("%s\n", struct_tab.call_format[i].format);
			printf("%d\n", struct_tab.call_format[i].f(ap, stack, result));
			printf("ok format callr\n");
			if ((len_arg = struct_tab.call_format[i].f(ap, stack, result)) == -1)
				return (-1);
			break ;
		}
	}
	printf("ok format callr\n");
	if (i == 5 && stack->format)
	{
		if (!(*result = (char*)ft_memalloc(2)))
			return (-1);
		**result = stack->format;
		len_arg = 1;
	}
	printf("ok format callr\n");
	return (len_arg);
}

static int		attributs_caller(char **result, t_struct_tab struct_tab,\
		t_stack *stack, int len_arg)
{
	int			i;
	int			j;
//	t_attributs	*call_attr;

	i = -1;
//	call_attr = make_call_attr();
	while (stack->attributs && (stack->attributs)[++i])
	{
		j = -1;
		while (++j < 3)
			if (struct_tab.call_attr[j].attr == (stack->attributs)[i])
			{
				if ((len_arg = struct_tab.call_attr[j].f(result,\
								stack, len_arg)) == -1)
					return (-1);
				break ;
			}
	}
	return (len_arg);
}

int				ft_stack_applier(t_stack *stack, t_struct_tab struct_tab,\
		char (*buff)[BUFF_SIZE], int *len)
{
	char	*result;
	int		len_arg;

	result = NULL;
	printf("ok stack\n");
	if ((len_arg = format_caller(struct_tab, struct_tab.ap, &result,\
					stack)) == -1)
		return (-1);
	if (!result)
		return (*len);
	printf("ok stack\n");
	if ((len_arg = attributs_caller(&result, struct_tab,\
					stack, len_arg)) == -1)
		return (-1);
	printf("ok stack\n");
	if ((len_arg = ft_width(&result, stack, len_arg)) == -1)
		return (-1);
	printf("ok stack\n");
	concat_buff(buff, result, len_arg, len);
	ft_strdel(&result);
	printf("ok stack\n");
	return (*len);
}
