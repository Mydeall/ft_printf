/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/04 19:57:22 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

#include <stdio.h>
# include "libft/libft.h"
#include <stdarg.h>

typedef struct		s_stack
{
	char			*attributs;
	int				width;
	int				precision;
	char			*modifier;
	char			format;
}					t_stack;

int					ft_printf(const char * restrict format, ...);
void				print_node(t_stack *current);
void				node_reset(t_stack *lst);
int					stack_applier(t_stack *stack, va_list ap);
char    			*int_format(int arg, t_stack *stack);
char    			*precision(char *result, t_stack *stack);
int					 int_modifier(int arg, t_stack *stack);
char    			*int_conversion(int arg, t_stack *stack);
char			    *ft_width(char *result, int width, char c, int side);
char    			*ft_zero(int arg, char *result, t_stack *stack);
char			    *ft_hashtag(int arg, char *result, t_stack *stack);

typedef struct		s_attributs
{
	char			attr;
	char			*(*f)(int, char*, t_stack*);
}					t_attributs;

#endif
