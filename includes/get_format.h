/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:00:18 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/11 14:00:25 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_format g_format_tab[] =
{
	{"#+-0 ", &get_attributs},
	{"0123456789", &get_width},
	{".", &get_precision},
	{"hlL", &get_modifier},
};