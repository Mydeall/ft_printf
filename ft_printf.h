/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/03 16:56:52 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct		s_stack
{
	char			*attributs;
	int				width;
	int				precision;
	char			*modifier;
	char			format;
	struct s_stack	*next;
}					t_stack;

int					ft_printf(const char * restrict format, ...);
void				print_node(t_stack *current);
void				print_lst(t_stack *stack);
void				lst_add_back(t_stack **lst, t_stack *new);

#endif
