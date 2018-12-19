/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:06:56 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/19 17:52:11 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static size_t	ft_arg(const char *restrict *format,\
	t_struct_tab struct_tab, char (*buff)[BUFF_SIZE], int len)
{
	int		i;

	node_reset(&struct_tab.stack);
	if ((i = ft_format_parser(*format, &struct_tab.stack, struct_tab)) == -1)
		return (-1);
	*format = &(*format)[i];
	if ((len = ft_stack_applier(&struct_tab.stack, struct_tab, buff, &len)) == -1)
		return (-1);
	free_node(&struct_tab.stack);
	return (len);
}

void			concat_buff(char (*buff)[BUFF_SIZE], char *str, int i,\
		int *len)
{
	int j;

	j = -1;
	while (++j < i)
	{
		(*buff)[(*len % BUFF_SIZE) + j] = str[j];
		if ((*len % BUFF_SIZE) + j == BUFF_SIZE)
		{
			write(1, *buff, BUFF_SIZE);
			*len += j;
			i -= j;
			j = -1;
		}
	}
	*len += j;
}

static t_struct_tab	make_struct_tab(void)
{
	t_struct_tab struct_tab;
	t_stack stack;

	node_reset(&stack);
	struct_tab.stack = stack;
	struct_tab.format_tab = make_format_tab();
	struct_tab.call_format= make_call_format();
	struct_tab.call_attr = make_call_attr();
	printf("OK\n");
	return (struct_tab);
}
/*
static void	free_struct_tab(t_struct_tab struct_tab)
{
	printf("free\n");
	free(struct_tab.format_tab);
	struct_tab.format_tab = NULL;
	free(struct_tab.call_format);
	struct_tab.call_format = NULL;
	free(struct_tab.call_attr);
	struct_tab.call_attr = NULL;
	va_end(struct_tab.ap);
	printf("free\n");
}
*/
int				ft_printf(const char *restrict format, ...)
{
	int		i;
	int		len;
	char	buff[BUFF_SIZE];
	t_struct_tab struct_tab;

	if (!(format))
		return (0);
	printf("OK\n");
	struct_tab = make_struct_tab();
	printf("OK\n");
	va_start(struct_tab.ap, format);
	len = 0;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			concat_buff(&buff, (char*)format, i, &len);
			format = &format[i];
			i = -1;
			if ((len = ft_arg(&format, struct_tab, &buff, len)) == -1)// EST-CE QU'IL FAUT VRAIMENT COUPER SI -1?
				return (-1);
		}
	concat_buff(&buff, (char*)format, i, &len);
	write(1, buff, len % BUFF_SIZE);
//	free_struct_tab(struct_tab);
	return (len);
}
