/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_caller.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:31:15 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/12 13:02:51 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_call_format	g_call_format[] =
{
	{"diouxXpb", &int_format},
	{"s", &str_format},
	{"c", &char_format},
	{"f", &double_format},
	{"%", &percent_format},
};
