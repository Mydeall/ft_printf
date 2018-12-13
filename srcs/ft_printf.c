/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:06:56 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/13 14:41:52 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static size_t	ft_arg(const char *restrict *format,\
	va_list ap, char (*buff)[BUFF_SIZE], int len)
{
	int		i;
	t_stack	stack;

	node_reset(&stack);
	if ((i = ft_format_parser(*format, &stack)) == -1)
		return (-1);
	*format = &(*format)[i];
	if ((len = ft_stack_applier(&stack, ap, buff, &len)) == -1)
		return (-1);
	free_node(&stack);
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

int				ft_printf(const char *restrict format, ...)
{
	int		i;
	int		len;
	char	buff[BUFF_SIZE];
	va_list	ap;

	if (!(format))
		return (0);
	va_start(ap, format);
	len = 0;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			concat_buff(&buff, (char*)format, i, &len);
			format = &format[i];
			i = -1;
			if ((len = ft_arg(&format, ap, &buff, len)) == -1)// EST-CE QU'IL FAUT VRAIMENT COUPER SI -1?
				return (-1);
		}
	concat_buff(&buff, (char*)format, i, &len);
	write(1, buff, len % BUFF_SIZE);
	va_end(ap);
	return (len);
}
