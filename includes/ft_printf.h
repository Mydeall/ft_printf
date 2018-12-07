/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/07 15:21:01 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdarg.h>
typedef unsigned long long int ULLI;

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
char    			*int_format(ULLI arg, t_stack *stack);
char    			*precision(char *result, t_stack *stack);
long long int		int_modifier(ULLI arg, t_stack *stack);
ULLI				unsigned_modifier(ULLI arg, t_stack *stack);
char    			*unsigned_conversion(ULLI arg, t_stack *stack);
char			    *ft_width(char *result, t_stack *stack);
char			    *ft_hashtag(char *result, t_stack *stack);
char    			*ft_zero(char *result, t_stack *stack);
char				*ft_minus(char *result, t_stack *stack);
char				*ft_plus(char *result, t_stack *stack);
char				*ft_space(char *result, t_stack *stack);
char				*str_format(char *arg, t_stack *stack);
char				*f_format(long double arg, t_stack *stack);
long double			f_modifier(long double arg, t_stack *stack);

typedef struct		s_attributs
{
	char			attr;
	char			*(*f)(char*, t_stack*);
}					t_attributs;

#endif
